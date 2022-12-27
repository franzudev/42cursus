import { Injectable } from "@nestjs/common"
import { ConfigService } from "@nestjs/config"
import { PassportStrategy } from "@nestjs/passport"
import { ExtractJwt, Strategy } from "passport-jwt"

@Injectable()
export class JwtStrategy extends PassportStrategy(Strategy) {
    constructor(
        private readonly configService: ConfigService
    ) {
        super({
            jwtFromRequest: ExtractJwt.fromExtractors([(req) => {
                return (req?.cookies) ? req.cookies['token'] : null
                // let token = null;
                // if (req?.cookies) {
                // 	token = req.cookies['token'];
                // }
                // return token;
            }]),
            ignoreExpiration: false,
            secretOrKey: configService.get<string>("JWT_SECRET")
        })
    }

    async validate(payload: { username: string, id: number }) {
        return {
            username: payload.username,
            user_id: payload.id
        }
    }
}
