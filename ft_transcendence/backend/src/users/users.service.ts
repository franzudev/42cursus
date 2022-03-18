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

  async findOne(username: string) {
    return await this.usersRepository.findOne({ username });
  }

  async findById(id: number) {
    return await this.usersRepository.find({
      relations: ['friends'],
      where: (qb) => {
        qb.where("User.id = :id", { id })
      }
    });
  }

  update(id: number, updateUserDto: UpdateUserDto) {
    return this.usersRepository.update(id, updateUserDto);
  }

  remove(id: number) {
    return this.usersRepository.delete(id);
  }

  async findFriends(id: number) {
    const [user] = await this.usersRepository.find({
      relations: ['friends'],
      where: (qb) => {
        qb.where("User.id = :id", { id })
      }
    })
    return user.friends
  }

  async addFriend(id: number, friendId) {
    const [user] = await this.findById(id)
    const [friend] = await this.findById(friendId)
    if (!user.friends)
      user.friends = []
    user.friends.push(friend)
    return this.usersRepository.save(user);
  }

  async storeMessage(message: Message) {
    let user = await this.findOne(message.room)
    if (user == null)
      return
  }
}
