import {
	HttpException,
	Module,
  } from '@nestjs/common';
  import { AuthService } from './auth.service';
  import { UsersModule } from '../users/users.module';
  import { AuthController } from './auth.controller';
  import { Api42Strategy } from './api42.strategy';
import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { UsersService } from 'src/users/users.service';
import { HttpModule } from '@nestjs/axios';
  
  @Module({
	imports    : [
	  UsersModule,
	  HttpModule
	],
	providers  : [
	  AuthService,
	  Api42Strategy
	],
	controllers: [
	  AuthController,
	],
  })
  export class AuthModule {}
  