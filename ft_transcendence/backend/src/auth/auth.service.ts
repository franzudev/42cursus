import {
	Injectable,
	UnauthorizedException,
} from '@nestjs/common';
import { User } from 'src/users/entities/user.entity';
import { UsersService } from '../users/users.service';
import { Repository } from 'typeorm';
import { HttpService } from '@nestjs/axios';
import { JwtService } from "@nestjs/jwt";

@Injectable()
export class AuthService
{
	constructor(
		private readonly usersService: UsersService
	) {}
	async findUserById(user_id: string): Promise<any> {
		const user = await this.usersService.findOne(user_id);

		if ( !user ) {
			throw new UnauthorizedException();
		}

		return user;
	}
	find_user_by_name(user_to_check: string): any {
		const user = this.usersService.findOne(user_to_check);
		if (!user)
		{
			console.log('inside find user by name (not found)');
			// insert new user and return it
			return null;
		}
		else
		{
			return user;
		}
	}
}
