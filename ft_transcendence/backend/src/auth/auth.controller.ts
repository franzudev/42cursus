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

const clientID = 'bfc424aaa222c55c5fc81959025e19226068f2c79ca67c3999295f2bf2f36b92';
const clientSecret = 'a6ace8b6a2e2a68ce05dabb9823f8a3031c66d91c775d5f2dc9b34dee72fa236';
const callbackURL = 'http://localhost:5050/auth/success';

@Controller('auth')
export class AuthController
{
	@Get('api42')
	@UseGuards(AuthGuard('api42'))
	async getUserFromLogin(@Req() req): Promise<any> {

		return req.user;
	}

	@UseGuards(AuthGuard('api42'))
	@Post('login')
	async login(@Request() req) {
		return req.user;
	}

	@Get('/success')
	@UseGuards(AuthGuard('api42'))
	parse_code(@Request() req, @Res() res: Response) {
		console.log('Res is: ', req.user);
		res.sendStatus(200);
		return req.user;
	}
	// @Get('/success') // /auth/redirect 
	// parse_code(@Query('code') code_: string) {
	// 	const axios = require('axios');
	// 	let access_token; 
	// 	axios({
	// 		method: 'post',
	// 		url: 'https://api.intra.42.fr/oauth/token',
	// 		data: {
	// 		  grant_type: 'authorization_code',
	// 		  client_id: clientID,
	// 		  client_secret: clientSecret,
	// 		  code: code_,
	// 		  redirect_uri: callbackURL
	// 		}
	// 	  }).then(function (response) {
	// 		  console.log(response.data.access_token);
	// 			access_token = response.data.access_token;
	// 			const me_url = 'https://api.intra.42.fr/v2/me';

	// 			axios.get(me_url, { headers: {"Authorization" : `Bearer ${access_token}`} })
	// 			.then(res => {
	// 				let username = res.data.login;
	// 				console.log(res.data.login);

	// 				axios.get(`http://localhost:5050/users/username?user=${username}`).then(res => {
	// 					if (res.data == '')
	// 					{
	// 						console.log('user doesnt exist');
	// 						axios.post('http://localhost:5050/users', {
	// 							username: username,
	// 							oauthToken: access_token
	// 						}).then(res => {
	// 							console.log('user added!')
	// 							console.log(res);
	// 						})
	// 					}	// subscribe user
	// 					else
	// 					{
	// 						axios.get(`http://localhost:5050/auth/setusername?user=${username}`).then(res => {
	// 							console.log('response from set session is ', res);
	// 						});
	// 						console.log('user found!'); // create a session and store user in it
	// 					}
	// 				})
					

	// 			});
	// 		 // console.log(response);
	// 	  })

	// }

	@Get('/views')
	getViews(@Session() session: { username?: string, views? : number }) {
		// return session.username;
		return session.username;
	}

	@Get('/setusername')
	set_user_session(@Query('user') user: string, @Session() session: { username?: string, views? : number }) {
	
		session.username = user;
		return session.username;
	}

	// @Get()
	// saiHi() { return ' Hi!'; };
}

