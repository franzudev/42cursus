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
		const jwt = this.jwtService.sign({username: req.user.username, id: req.user.id});
		res.cookie('token', jwt, { httpOnly: true });
		res.header({jwt})
  		res.json({ jwt });
		return jwt;
	}

	@Get('/test')
	@UseGuards(JwtAuthGuard)
	test_service(@Request() req) {
		console.log(req.user);
		return 'youre inside guard'
	}



	@Get('/set_number') // use guards JWTAUTHGUARD 
	@UseGuards(JwtAuthGuard)
	async set_user_number(@Request() req, @Res() res: Response, @Query('number') number: string) { 
		let result = await this.authService.create_2fa_code(number);
		console.log(result); 
	}

	@Get('/update_user_test')
	@UseGuards(JwtAuthGuard)
	update_user(@Request() req, @Res() res: Response, @Query('number') number: string) {
		const user = req.user;
		const id = user.user_id;
		console.log(user);
		// let id = user.id;
		return this.authService.update_user_number(id, number);
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

