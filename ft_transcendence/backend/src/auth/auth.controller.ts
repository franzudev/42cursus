import
{
	Controller,
	Get,
	Post,
	Request,
	Res,
	Req,
	Query,
	Session,
	UseGuards,
} from '@nestjs/common';


import { HttpService } from '@nestjs/axios'
import { AuthGuard } from '@nestjs/passport';
import { User } from 'src/users/entities/user.entity';
import { AuthService } from './auth.service';
import { Api42Strategy } from './api42.strategy';
import { UsersService } from 'src/users/users.service';
import { stringify } from 'querystring';
import { Serialize } from 'src/users/users.interceptor';
import { Response } from 'express';
import { JwtService } from '@nestjs/jwt';
import { JwtAuthGuard } from './jwt-auth.guard';

const clientID = 'bfc424aaa222c55c5fc81959025e19226068f2c79ca67c3999295f2bf2f36b92';
const clientSecret = 'a6ace8b6a2e2a68ce05dabb9823f8a3031c66d91c775d5f2dc9b34dee72fa236';
const callbackURL = 'http://localhost:5050/auth/success';

@Controller('auth')
export class AuthController
{
	constructor(
		private authService: AuthService,
		private jwtService: JwtService
	) {}

	@Get('api42')
	@UseGuards(AuthGuard('api42'))
	async getUserFromLogin(@Req() req): Promise<any> {
		return req.user;
	}

	@Get('/login')
	sendLink() {
		return `<a href='http://localhost:5050/auth/api42'>VALIDATE</a>`;
	}

	/////	 google auth generation		/////

	@Get('/generate_qr')
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

	@Get('/verify_g_code')
	@UseGuards(JwtAuthGuard)
	async verifyQrCode(@Request() req, @Res() res: Response, @Query('code') code: string) {
		const user = await this.authService.findUserByName(req.user.username);
		const secret_code = user.twoFactorAuthCode; // this should be retrieved from db 
		const data = this.authService.verifyGCode(code, secret_code);
		data.subscribe((value: any) => {
			if (value.data == 'True') {
				this.authService.updateUser2fa(user.id);
				res.send('approved');
			}
			else {
				res.send('FAILED');
			}
		});
	}

	@Get('/verify_login_2fa')
	async verifyLogin2fa(@Request() req, @Res() res: Response, @Query('code') code: string, @Query('username') username: string) {
		const user = await this.authService.findUserByName(username);
		const secret_code = user.twoFactorAuthCode; // this should be retrieved from db 
		const data = this.authService.verifyGCode(code, secret_code);
		data.subscribe((value: any) => {
			if (value.data !== "True") {
				res.send('FAILED');
			}
			else {
				const jwt = this.jwtService.sign({username: user.username, id: user.id});
				res.cookie('token', jwt, { httpOnly: true });
				res.send('approved');
				
			}
		});
	}
	/////	 google auth	/////


	@Get('/success')
	@UseGuards(AuthGuard('api42'))
	async parseCode(@Request() req, @Res() res: Response) {

		const user = await this.authService.findUserByName(req.user.username);

		if (user.twoFactorEnabled) {
			res.redirect(`http://localhost:3000/validation_code?username=${user.username}`);
			return ;
		}
		else
		{
			const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
			res.cookie('token', jwt, { httpOnly: true });
			res.redirect('http://localhost:3000/profile');
			return jwt;
		}
	}

	@Get('/test')
	@UseGuards(JwtAuthGuard)
	async testService(@Request() req) {
		 console.log(req.user.user_id);
		const user = await this.authService.findUserById(req.user.user_id);
		console.log(user);
		return 'youre inside guard';
	}

}

