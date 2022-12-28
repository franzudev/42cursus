import { UsersGateway } from "./gateway/users.gateway";
import { forwardRef, Module } from "@nestjs/common";
import { UsersService } from "./users.service";
import { UsersController } from "./users.controller";
import { TypeOrmModule } from "@nestjs/typeorm";
import { User } from "./entities/user.entity";
import { HttpModule } from "@nestjs/axios";
import { AuthModule } from "@/auth/auth.module";
import { JwtStrategy } from "@/auth/jwt.strategy";
import { Api42Strategy } from "@/auth/api42.strategy";
import { RedisService } from "@/redis/redis.service";

@Module({
    imports: [
        TypeOrmModule.forFeature([User]),
        HttpModule,
        forwardRef(() => AuthModule),
    ],
    controllers: [UsersController],
    providers: [
        UsersGateway,
        UsersService,
        RedisService,
        JwtStrategy,
        Api42Strategy,
    ],
    exports: [UsersService],
})
export class UsersModule {}
