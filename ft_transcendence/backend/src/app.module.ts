import { Module } from '@nestjs/common'
import { TypeOrmModule } from '@nestjs/typeorm'
import { AppController } from './app.controller'
import { AppService } from './app.service'
import { UsersModule } from './users/users.module'
import { RoomsModule } from './rooms/rooms.module'
import { AuthModule } from './auth/auth.module'
import { PassportModule } from '@nestjs/passport'
import { ConfigModule } from "@nestjs/config"
import { DatabaseConfigService } from "./database-config.service"
import { ServeStaticModule } from '@nestjs/serve-static'
import { join } from 'path'
import { RedisService } from './redis/redis.service'


@Module({
    imports: [
        PassportModule.register({session: true}),
        ConfigModule.forRoot({
            isGlobal: true,
            envFilePath: [`.env${process.env.STAGE}`]
        }),
        TypeOrmModule.forRootAsync({
            useClass: DatabaseConfigService,
            inject: [DatabaseConfigService]
        }),
        ServeStaticModule.forRoot({
            rootPath: join(__dirname, '..', 'public')
        }),
        AuthModule,
        UsersModule,
        RoomsModule
    ],
    controllers: [AppController],
    providers: [AppService, RedisService]
})
export class AppModule {
}
