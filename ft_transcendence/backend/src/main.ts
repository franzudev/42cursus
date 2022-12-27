import {NestFactory} from '@nestjs/core';
import {AppModule} from './app.module';

import * as session from 'express-session';
import * as passport from 'passport'
// somewhere in your initialization file
import * as cookieParser from 'cookie-parser';
import {ConfigService} from "@nestjs/config"

// somewhere in your initialization file

async function bootstrap() {
    const app = await NestFactory.create(AppModule);
    const configService = app.get(ConfigService);

    app.use(
        session({
            cookie: {
                maxAge: parseInt(configService.get("COOKIE_MAX_AGE"))
            },
            secret: configService.get("COOKIE_SECRET"),
            resave: false,
            saveUninitialized: false, // save sessions only if user is logged in
        }),
    );
    app.use(passport.initialize());
    app.use(passport.session());
    app.use(cookieParser());

    app.enableCors({
        credentials: true,
        origin: `${configService.get("APP_URL")}`
    });

    await app.listen(5050);
}

bootstrap();
