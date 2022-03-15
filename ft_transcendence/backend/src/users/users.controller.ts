import {
  Controller,
  Get,
  Post,
  Body,
  Req,
  Request, 
  Res,
  Patch,
  Query,
  Param,
  Delete,
  UseGuards
} from '@nestjs/common';
import { UsersService } from './users.service';
import { CreateUserDto } from './dto/create-user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { Serialize } from "./users.interceptor";
import { UserDto } from "./dto/user.dto";

/******** GUARDS **********/
import { AuthGuard } from '@nestjs/passport';
import { AuthService } from '../auth/auth.service';
import { Api42Strategy } from '../auth/api42.strategy';
import { User } from './entities/user.entity';
import { Response } from 'express';
import { JwtAuthGuard } from 'src/auth/jwt-auth.guard';

@Controller('users')
@Serialize(UserDto)
export class UsersController {
  userService: any;
  constructor(private readonly usersService: UsersService) {}

  @Post()
  async create(@Body() createUserDto: CreateUserDto) {
    return await this.usersService.create(createUserDto);
  }

  @Get()
  findAll() {
    return this.usersService.findAll();
  }

  @Get('/username')
  find_by_user(@Query('user') user: string) {
    const user_ = this.usersService.find_one_by_username(user);
    user_.then((res) => {
      console.log(res);
    })
    return user_;
  }

  @Get(':id')
  @UseGuards(JwtAuthGuard)
  findOne(@Req() req, @Param('id') id: string) {
    console.log(req.user);
    return this.usersService.findOne(+id);
  }

  @Patch(':id')
  update(@Param('id') id: string, @Body() updateUserDto: UpdateUserDto) {
    return this.usersService.update(+id, updateUserDto);
  }

  @Delete(':id')
  remove(@Param('id') id: string) {
    return this.usersService.remove(+id);
  }
  // login endpoint
  @Get('login')
  @UseGuards(AuthGuard('api42'))
  async login(@Req() req, @Res() res: Response) {
    return req.user;
  }

}

