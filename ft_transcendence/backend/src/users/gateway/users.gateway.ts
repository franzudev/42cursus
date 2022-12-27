import {UsersService} from './../users.service';
import {Logger} from '@nestjs/common';
import {
  ConnectedSocket,
  MessageBody,
  OnGatewayConnection,
  OnGatewayDisconnect,
  OnGatewayInit,
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer
} from '@nestjs/websockets';
import {Server, Socket} from 'socket.io';
import {Message} from "../../rooms/entities/message.entity";
import {RedisService} from "../../redis/redis.service";
import {UserStatus} from "../entities/user-status.entity";

@WebSocketGateway({
  cors: {
    origin: '*',
  },
})
export class UsersGateway implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect {

  constructor(
      private readonly usersService: UsersService,
      private readonly redisService: RedisService
  ) {
  }

  @WebSocketServer()
  private server: Server;

  private logger: Logger = new Logger('UsersGateway');

  @SubscribeMessage('dm')
  // @UseGuards(JwtAuthGuard)
  async handleMessage(
      @ConnectedSocket() client: Socket,
      @MessageBody() message: Message,
  ): Promise<void> {
    this.logger.log(await this.redisService.getKey(client.id))
    this.server.to(message.room).emit('send-message', message);
    this.usersService.storeMessage(message)
  }

  afterInit(server: Server) {
    this.logger.log('Init');
  }

  handleDisconnect(client: Socket) {
    this.redisService.setKey(client.id, UserStatus.OFFLINE)
  }

  handleConnection(client: Socket, ...args: any[]) {
    this.redisService.setKey(client.id, UserStatus.ONLINE)
  }
}
