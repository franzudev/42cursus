import { Injectable } from "@nestjs/common";
import { ConfigService } from "@nestjs/config";
import { PassportStrategy } from "@nestjs/passport";
import { ExtractJwt, Strategy } from "passport-jwt";

@Injectable()
export class JwtStrategy extends PassportStrategy(Strategy) {
	constructor(
		private readonly configService: ConfigService
	) {
		super({
			jwtFromRequest: ExtractJwt.fromExtractors([ (req) => {
				var token = null;
				if (req && req.cookies) {
					token = req.cookies['token'];
				}
				return token;
			} ]),
			ignoreExpiration: false,
			secretOrKey: configService.get<string>("JWT_SECRET"),
 		});
	}

	async validate(payload: { username: string, id: number }) {
		return {
			username: payload.username,
			user_id: payload.id,
		};
	}
}
