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

	@Get('/verify_2fa')
	async verify_code(@Request() req, @Res() res: Response, @Query('code') code: string, @Query('username') username: string) {
		const user = await this.authService.find_user_by_name(username);
		const ver_res = await this.authService.verify_code(user.telephoneNumber, code);
		console.log(ver_res);

		if (ver_res == 'approved') {
			const jwt = this.jwtService.sign({username: user.username, id: user.id});
			res.cookie('token', jwt, { httpOnly: true });
			res.header({jwt})
			res.json({ jwt });
			res.redirect('http://localhost:3000/profile');
		}
		else
			res.json({ver_res});
	}

	@Get('/success')
	@UseGuards(AuthGuard('api42'))
	async parse_code(@Request() req, @Res() res: Response) {

		const user = await this.authService.find_user_by_name(req.user.username);

		if (user.twoFactorEnabled) {
			const req = await this.authService.create_2fa_code(user.telephoneNumber);
			res.cookie('username', user.username);
			res.redirect(`http://localhost:3000/validation_code?username=${user.username}`);
			return ;
		}
		else
		{
			const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
			res.cookie('token', jwt, { httpOnly: true });
			res.header({jwt})
			res.json({ jwt });
			res.redirect('http://localhost:3000/profile');
			return jwt;
		}
	}

	@Get('/whoami')
	// @UseGuards(JwtAuthGuard)
	who_am_i(@Request() req, @Res() res: Response) {
		if (!req.cookies.token) { 
			res.send('KO');
		}
		else
			res.send('OK');
	}

	@Get('/test')
	@UseGuards(JwtAuthGuard)
	test_service(@Request() req) {
		console.log(req.user);
		return 'youre inside guard';
	}

	@Get('/set_number') // use guards JWTAUTHGUARD 
	@UseGuards(JwtAuthGuard)
	async set_user_number(@Request() req, @Res() res: Response, @Query('number') number: string) { 
		let result = await this.authService.create_2fa_code(number);
		console.log(result); 
	}

	@Get('/find_user')
	async find_user(@Query('username') username: string) {
		let user;
		
		user = await this.authService.find_user_by_name(username);
		console.log('user is', user.id);
		return user;
	}

	@Get('/verify_status') // use guards JWTAUTHGUARD
	@UseGuards(JwtAuthGuard)
	async verify_status(@Request() req, @Res() res: Response, @Query('number') number: string, @Query('code') code: string) {
		 let verification_res = await this.authService.verify_code(number, code); 

		 res.send(verification_res);
		 if (verification_res != 'approved')
			 console.log('verification not approved'); // do nothing;
		 else
		 {
			const user = req.user;
			const id = user.user_id;
			 this.authService.update_user_number(id, number);
			 console.log('verification correctly approved');
		 }
	}
}

