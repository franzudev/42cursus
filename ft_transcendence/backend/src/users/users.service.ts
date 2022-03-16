import { HttpService } from '@nestjs/axios';
import  { AxiosResponse } from 'axios'
import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { map, Observable } from 'rxjs';
import { Repository } from 'typeorm';
import { CreateUserDto } from './dto/create-user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { User } from './entities/user.entity';
import { Message } from "../rooms/entities/message.entity";
import { JwtService } from '@nestjs/jwt'

@Injectable()
export class UsersService {
  constructor(
    @InjectRepository(User) private usersRepository: Repository<User>,
    private jwtService:JwtService
  ) {}

  public async getJwtToken(user: User): Promise<string>{
    const payload = {
     ...user
    }
    return this.jwtService.signAsync(payload);
  }

  async create(createUserDto: CreateUserDto) {
    return await this.usersRepository.save(createUserDto);
  }

  generate(user: Partial<CreateUserDto>) {
    return this.usersRepository.create(user)
  }

  async findAll() {
    return await this.usersRepository.find();
  }

  findOne(username: string) {
    return this.usersRepository.findOne({ username });
  }

  update(id: number, updateUserDto: UpdateUserDto) {
    return this.usersRepository.update(id, updateUserDto);
  }

  remove(id: number) {
    return this.usersRepository.delete(id);
  }

  async storeMessage(message: Message) {
    let user = await this.findOne(message.room)
    if (user == null)
      return
  }
}
