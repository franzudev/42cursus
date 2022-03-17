import { IsOptional, IsString } from "class-validator";
import { User } from "../entities/user.entity";

export class CreateUserDto {

	@IsString()
	username: string;

	@IsString()
	oauthToken: string;

	@IsString()
	@IsOptional()
	avatar: string;

	@IsString()
	@IsOptional()
	twoFactorAuthCode: string;

	friends: User[]

}
