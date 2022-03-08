import
{
	Controller,
	Get,
	Req,
	UseGuards,
} from '@nestjs/common';
import { AuthGuard } from '@nestjs/passport';
import { User } from 'src/users/entities/user.entity';

@Controller('auth')
export class AuthController
{
	@Get('api42')
	@UseGuards(AuthGuard('api42'))
	async getUserFromDiscordLogin(@Req() req): Promise<any> {
		return req.user;
	}

	// @Get()
	// saiHi() { return ' Hi!'; };
}
