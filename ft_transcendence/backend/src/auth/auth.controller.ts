import {Controller, Get, Query, Request, Res, UseGuards} from '@nestjs/common';
import {AuthGuard} from '@nestjs/passport';
import {AuthService} from './auth.service';
import {Response} from 'express';
import {JwtService} from '@nestjs/jwt';
import {JwtAuthGuard} from './jwt-auth.guard';
import {ConfigService} from "@nestjs/config";
import {UsersService} from "../users/users.service";

@Controller('auth')
export class AuthController {
    constructor(
        private readonly authService: AuthService,
        private readonly jwtService: JwtService,
        private readonly usersService: UsersService,
        private readonly configService: ConfigService,
    ) {
    }

    @Get('/login')
    @Get('/generate-qr')
    @UseGuards(JwtAuthGuard)
    generateQr(@Request() req, @Res() res: Response) {
        const username = req.user.username;
        const secret_code = this.authService.generateRandomString(10);
        const data = this.authService.generateQrCode(username, secret_code);
        this.authService.updateUserAuthCode(req.user.user_id, secret_code);
        // save this secret generated code into database
        data.subscribe((value) => {
            res.send(value.data);
        });
    }

    @Get('/verify-g-code')
    @UseGuards(JwtAuthGuard)
    async verifyQrCode(@Request() req, @Res() res: Response, @Query('code') code: string) {
        const user = await this.usersService.findOne(req.user.username);
        const secret_code = user.twoFactorAuthCode; // this should be retrieved from db
        const data = this.authService.verifyGCode(code, secret_code);
        data.subscribe((value: any) => {
            if (value.data == 'True') {
                this.authService.updateUser2fa(user.id);
                res.send('approved');
            }
            res.send('FAILED');
        });
    }

    @Get('/verify-login-2fa')
    async verifyLogin2fa(@Request() req, @Res() res: Response, @Query('code') code: string, @Query('username') username: string) {
        const user = await this.usersService.findOne(username)
        const data = this.authService.verifyGCode(code, user.twoFactorAuthCode);
        data.subscribe((value: any) => {
            if (value.data === "True") {
                const jwt = this.jwtService.sign({username: user.username, id: user.id});
                res.cookie('token', jwt, {httpOnly: true});
                res.send('approved');
            }
            res.send('FAILED');
        });
    }

    @Get('/success')
    @UseGuards(AuthGuard('api42'))
    async parseCode(@Request() req, @Res() res: Response) {
        const user = await this.usersService.findOne(req.user.username)
        if (user.twoFactorEnabled) {
            res.redirect(`${this.configService.get<string>("APP_URL")}/validation_code?username=${user.username}`);
            return;
        } else {
            const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
            res.cookie('token', jwt, {httpOnly: true});
            res.redirect(`${this.configService.get<string>("APP_URL")}/profile`);
            return jwt;
        }
    }

    @Get('/test')
    @UseGuards(JwtAuthGuard)
    test_service() {
        return 'youre inside guard'
    }

    @Get('/views')
    // @UseGuards(JwtAuthGuard)
    getViews(@Request() req) {
        // return session.username;
        console.log(req.cookies.token);
        return req.cookies.token;
    }

}

