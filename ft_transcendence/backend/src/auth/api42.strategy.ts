import { PassportStrategy } from '@nestjs/passport';
import {
	Injectable,
} from '@nestjs/common';
import { HttpService } from '@nestjs/axios';
import { AuthService } from './auth.service';
import { Strategy } from 'passport-oauth2';
import { stringify } from 'querystring';



const clientID = '8a37c2bd21158cbb8c1ad6998953125894bc483c66d58b9d35a8d2759b3120f6';
const clientSecret = '5c0ce0d7032bcac83f015fff87e77d52eab3ff8df0e91b4d2a04554d23d69ab2';
const callbackURL = 'http://localhost:3000/success.html';

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
				response_type: 'code'
				// scope        : 'identify',
			}) }`,
			tokenURL        : 'https://api.intra.42.fr/oauth/token',
			scope           : 'public',
			clientID,
			clientSecret,
			callbackURL,
		});
	}

	async validate(
		accessToken: string,
	): Promise<any> {
		const { data } = await this.http.get('https://api.intra.42.fr/v2/me', {
				headers: { Authorization: `Bearer ${ accessToken }` },
			})
			.toPromise();

		return this.authService.findUserById(data.id);
	}
}
