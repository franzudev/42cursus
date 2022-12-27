import { Injectable, UnauthorizedException } from '@nestjs/common'
import { UsersService } from '../users/users.service'
import { HttpService } from "@nestjs/axios"

@Injectable()
export class AuthService {
    constructor(
        private readonly usersService: UsersService,
        private readonly httpService: HttpService
    ) {
    }

    async findUserById(user_id: number): Promise<any> {
        const user = await this.usersService.findById(user_id)

        if (!user) {
            throw new UnauthorizedException()
        }
        return user
    }

    updateUserAuthCode(id: number, code: string) {
        return this.usersService.update(id, {twoFactorAuthCode: code})
    }

    updateUser2fa(id: number) {
        return this.usersService.update(id, {twoFactorEnabled: true})
    }

    generateQrCode(username: string, secret_code: string): any {
        return this.httpService.get(`https://www.authenticatorapi.com/pair.aspx?AppName=Transcendence&AppInfo=${username}&SecretCode=${secret_code}`)
    }

    verifyGCode(code: string, secret_code: string): any {
        return this.httpService.get(`https://www.authenticatorapi.com/Validate.aspx?Pin=${code}&SecretCode=${secret_code}`)
    }

    generateRandomString(length: number): string {
        let result: string = ''
        const characters: string = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'
        const charactersLength: number = characters.length
        for (let i = 0; i < length; i++) {
            result += characters.charAt(Math.floor(Math.random() * charactersLength))
        }
        return result
    }
}
