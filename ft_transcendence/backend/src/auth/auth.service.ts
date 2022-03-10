import {
	Injectable,
	UnauthorizedException,
} from '@nestjs/common';
import { User } from 'src/users/entities/user.entity';
import { UsersService } from '../users/users.service';
import { Repository } from 'typeorm';
import { HttpService } from '@nestjs/axios';

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
	find_user_by_name(user_to_check: string): any {
		const user = this.usersService.find_one_by_username(user_to_check);
		if (!user)
		{
			// insert new user and return it
			return 'uh oh, no one found :(';
		}
		else
		{
			return user;
		}
	}
}
