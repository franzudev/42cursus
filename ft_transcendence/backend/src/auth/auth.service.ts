import {
	Injectable,
	UnauthorizedException,
} from '@nestjs/common';
import { UsersService } from '../users/users.service';

const accountSid = 'AC4e30a402f30e79bfb4b5edda0f2debdf'; // Your Account SID from www.twilio.com/console
const authToken = '03916445b1f4faf6915c30642fd21b42';   // Your Auth Token from www.twilio.com/console

const client = require('twilio')(accountSid, authToken);

@Injectable()
export class AuthService
{
	constructor(
		private readonly usersService: UsersService
	) {}

	async findUserById(user_id: string): Promise<any> {
		const user = await this.usersService.findOne(user_id);

		if (!user) {
			throw new UnauthorizedException();
		}
		return user;
	}

	find_user_by_name(user_to_check: string) {
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

	async create_2fa_code(number_to_send: string) : Promise<any> {
		return await  client.verify.services('VA1a21b7237f89cb69dd66a53379971c6a')
      .verifications
      .create({to: number_to_send, channel: 'sms'})
	  .catch((err) => {
		  return err;
	  })
      .then((verification_check) =>  { 

		  console.log(verification_check.status);
			return verification_check.status;			
		});
	}

	async verify_code(number_to_send: string, code_to_verify: string) : Promise<any> {
		return await client.verify.services('VA1a21b7237f89cb69dd66a53379971c6a')
		.verificationChecks
		.create({to: number_to_send, code: code_to_verify})
		.catch((err) => {
			return err;
		})
		.then((verification_check) => {
			return (verification_check.status)
		});
	  }
	
	  update_user_number(id: number, number_to_insert: string) {
		return this.usersService.update(id, { twoFactorEnabled: true, telephoneNumber: number_to_insert }); 
	  }
 }
