import
{
	Controller,
	Get,
	Request,
	Res,
	Req,
	Query,
	Session,
	UseGuards, Redirect,
} from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
import { AuthService } from './auth.service';
import { Response } from 'express';
import { JwtService } from '@nestjs/jwt';
import { JwtAuthGuard } from './jwt-auth.guard';
import { ConfigService } from "@nestjs/config";
import { strict } from "assert";

@Controller('auth')
export class AuthController
{
	constructor(
		private readonly authService: AuthService,
		private readonly jwtService: JwtService,
		private readonly configService: ConfigService,
	) {}

	@Get('/login')
	@UseGuards(AuthGuard('api42'))
	parse_code(@Request() req, @Res() res: Response) {
		const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
		res.cookie('token', jwt, { httpOnly: true });
		res.header({ jwt })
		return res.redirect(this.configService.get<string>("APP_URL"))
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

	@Get('/setusername')
	set_user_session(@Query('user') user: string, @Session() session: { username?: string, views? : number }) {
		session.username = user;
		return session.username;
	}
}

