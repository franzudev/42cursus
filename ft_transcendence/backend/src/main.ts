import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';

import * as session from 'express-session';
import * as passport from 'passport'
// somewhere in your initialization file

import * as cookieParser from 'cookie-parser';
// somewhere in your initialization file



async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  app.use(
    session({
      cookie: {
        maxAge: 60000 * 60 * 24 // 1 m per 60m * 24 h
      },
      secret: 'my-secret', // cookie encryption
      resave: false,
      saveUninitialized: false, // save sessions only if user is logged in
    }),
  );
  app.use(passport.initialize());
  app.use(passport.session());
  app.use(cookieParser());
  app.enableCors({
      origin: "*"
  })

  await app.listen(5050);
}
bootstrap();
