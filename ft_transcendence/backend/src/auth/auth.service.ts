import {
	Injectable,
	UnauthorizedException,
} from '@nestjs/common';
import { User } from 'src/users/entities/user.entity';
import { UsersService } from '../users/users.service';
import { Repository } from 'typeorm';

@Injectable()
export class AuthService
{
	constructor(
		private readonly usersService: UsersService
	) {}
	async findUserById(user_id: number): Promise<any> {
		const user = await this.usersService.findOne(user_id);

		if ( !user ) {
			throw new UnauthorizedException();
		}

		return user;
	}
}
