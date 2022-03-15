import { PassportStrategy } from '@nestjs/passport';
import {
	Injectable,
} from '@nestjs/common';
import { HttpService } from '@nestjs/axios';
import { AuthService } from './auth.service';
import { Strategy } from 'passport-oauth2';
import { stringify } from 'querystring';
import { UsersService } from 'src/users/users.service';



const clientID = 'bfc424aaa222c55c5fc81959025e19226068f2c79ca67c3999295f2bf2f36b92';
const clientSecret = 'a6ace8b6a2e2a68ce05dabb9823f8a3031c66d91c775d5f2dc9b34dee72fa236';
const callbackURL = 'http://localhost:5050/auth/success';

@Injectable()
export class Api42Strategy extends PassportStrategy(Strategy, 'api42')
{
	constructor(
		private authService: AuthService,
		private http: HttpService
	) {
		
		super({
			authorizationURL: `https://api.intra.42.fr/oauth/authorize?${ stringify({
				client_id    : clientID,
				redirect_uri : callbackURL,
				response_type: 'code',
				scope        : ['public']
			}) }`,
			tokenURL        : 'https://api.intra.42.fr/oauth/token',
			scope           : 'public',
			clientID,
			clientSecret,
			callbackURL,
		});
		console.log('inside strategy constructor');
	}

	async validate(accessToken: string): Promise<any> {
		const internal_api_url = 'http://localhost:5050/users';
		console.log('inside strategy validation!');
		const { data } = await this.http.get('https://api.intra.42.fr/v2/me', {
				headers: { Authorization: `Bearer ${ accessToken }` },
			}).toPromise();
		console.log(data.login); // should print user intra name 
		const user = await this.authService.find_user_by_name(data.login);
		if (!user) // user isnt registered yet
		{
			console.log('user not found, creating it now...');
			return this.authService.create_user(accessToken, data.login, data.image_url);
		}
		else
			console.log('user found');
		return user;
	}
}
