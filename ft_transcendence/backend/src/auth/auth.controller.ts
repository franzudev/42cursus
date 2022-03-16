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
	send_link() {
		return `<a href='http://localhost:5050/auth/api42'>VALIDATE</a>`;
	}

	@Get('/success')
	@UseGuards(AuthGuard('api42'))
	parse_code(@Request() req, @Res() res: Response) : string {
		console.log('Res is: ', req.user);
		// res.sendStatus(200);
		const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
		console.log('jwt is ', jwt);
		// res.send(jwt);
		res.cookie('token', jwt, { httpOnly: true });
  		res.json({ jwt });
		return jwt;
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

