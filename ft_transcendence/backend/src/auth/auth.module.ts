import { forwardRef, Module } from '@nestjs/common';
import { AuthService } from './auth.service';
import { UsersModule } from '../users/users.module';
import { AuthController } from './auth.controller';
import { Api42Strategy } from './api42.strategy';
import { HttpModule } from '@nestjs/axios';
import { JwtModule } from '@nestjs/jwt';
import { PassportModule } from '@nestjs/passport';
import { JwtStrategy } from './jwt.strategy';
import { ConfigModule, ConfigService } from '@nestjs/config';

@Module({
    imports: [
        forwardRef(() => UsersModule),
        HttpModule,
        PassportModule,
        ConfigModule,
        JwtModule.registerAsync({
            imports: [ConfigModule],
            useFactory: async (configService: ConfigService) => ({
                secret: configService.get<string>("JWT_SECRET"),
                signOptions: {
                    expiresIn: configService.get<string>("JWT_EXPIRES_IN")
                }
            }),
            inject: [ConfigService]
        }),
    ],
    providers: [
        AuthService,
        Api42Strategy,
        JwtStrategy
    ],
    controllers: [
        AuthController,
    ],
    exports: [
        PassportModule,
        JwtStrategy,
        JwtModule
    ]
})
export class AuthModule {
}
