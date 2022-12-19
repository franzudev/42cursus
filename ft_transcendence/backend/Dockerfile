FROM node:16.14.0-alpine3.15

LABEL org.opencontainers.image.source https://github.com/franzudev/ft_transcendence

RUN npm install -g http-server

WORKDIR /app

COPY package*.json ./

RUN npm install

COPY . .

EXPOSE 5050
CMD [ "npm", "run", "start:dev" ]
