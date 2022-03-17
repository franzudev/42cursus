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
  UseGuards, UploadedFile, UseInterceptors, NotFoundException, BadRequestException, Logger
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
import { response, Response } from 'express';
import { JwtAuthGuard } from 'src/auth/jwt-auth.guard';
import { FileInterceptor } from "@nestjs/platform-express";
import * as fs from "fs";
import { diskStorage } from "multer";

@Controller('users')
@Serialize(UserDto)
export class UsersController {

  private logger: Logger = new Logger('UsersController');

  constructor(private readonly usersService: UsersService) {}

  @Post()
  async create(@Body() createUserDto: CreateUserDto) {
    return await this.usersService.create(createUserDto);
  }

  @Get()
  findAll() {
    return this.usersService.findAll();
  }

  @Get(':username')
  @UseGuards(JwtAuthGuard)
  findOne(@Param('username') username: string) {
    return this.usersService.findOne(username);
  }

  @Patch(':id')
  update(@Param('id') id: string, @Body() updateUserDto: UpdateUserDto) {
    return this.usersService.update(+id, updateUserDto);
  }

  @Delete(':id')
  remove(@Param('id') id: string) {
    return this.usersService.remove(+id);
  }

  @Get('/:id/friends')
  findFriends(@Param('id') id: string) {
    return this.usersService.findFriends(+id)
  }

  @Patch('/:id/add-friend')
  addFriend(@Param('id') id: string, @Body() { friendId }) {
    return this.usersService.addFriend(+id, friendId)
  }

  @Get('login')
  @UseGuards(AuthGuard('api42'))
  async login(@Req() req, @Res() res: Response) {
    return req.user;
  }

  @Post('/:username/avatar')
  @UseGuards(JwtAuthGuard)
  @UseInterceptors(FileInterceptor('avatar', {
    storage: diskStorage({
      destination: function (req, file, cb) {
        const path = process.env.AVATAR_PATH
        fs.mkdirSync(path, {
          recursive: true
        })
        cb(null, path);
      },
      filename: (req, file, cb) => {
        const filename = file.originalname.split(".")
        const extension = filename[filename.length - 1]
        cb(null, `${req.params.username}.${extension}`)
      }
    })
  }))
  async avatarUpload(@Param('username') username: string, @UploadedFile() file: Express.Multer.File) {
    const user = await this.usersService.findOne(username)
    if (!user) {
      fs.rm(`avatars/${file.filename}`, (err) => null)
      throw new NotFoundException()
    }
    user.avatar = file.filename;
    await this.usersService.update(user.id, user)
    return user;
  }

}
