import { IsOptional, IsString } from "class-validator";

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

}
