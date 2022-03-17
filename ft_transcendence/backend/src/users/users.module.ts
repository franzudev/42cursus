import { UsersGateway } from './gateway/users.gateway';
import { Module } from '@nestjs/common';
import { UsersService } from './users.service';
import { UsersController } from './users.controller';
import { TypeOrmModule } from '@nestjs/typeorm';
import { User } from './entities/user.entity';
import { HttpModule } from '@nestjs/axios';
import { JwtModule } from '@nestjs/jwt';


@Module({
    imports: [
        TypeOrmModule.forFeature([User]),
        HttpModule,
        JwtModule.register({
            secret: 'My random secret key never let others',
            signOptions: {
                expiresIn: '1h',
            },
        }),
    ],
    controllers: [UsersController],
    providers: [UsersGateway, UsersService],
    exports: [UsersService]
})
export class UsersModule {}
