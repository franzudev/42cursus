import { Expose } from 'class-transformer'

export class UserDto {

    @Expose()
    id: number;

    @Expose()
    username: string;

    @Expose()
    avatar: string;

    @Expose()
    twoFactorEnabled: boolean;

    @Expose()
    telephoneNumber: string;
}
