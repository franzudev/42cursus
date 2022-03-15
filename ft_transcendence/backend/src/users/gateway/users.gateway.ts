import { UsersService } from './../users.service';
import { Logger } from '@nestjs/common';
import {
  ConnectedSocket, MessageBody,
  OnGatewayConnection,
  OnGatewayDisconnect,
  OnGatewayInit,
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer
} from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';
import { Message } from "../../rooms/entities/message.entity";

@WebSocketGateway({
  cors: {
    origin: '*',
  },
})
export class UsersGateway implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect {

  constructor(private readonly usersService: UsersService) {}

  @WebSocketServer()
  private server: Server;

  private logger: Logger = new Logger('UsersGateway');

  @SubscribeMessage('dm')
  handleMessage(
      @ConnectedSocket() client: Socket,
      @MessageBody() message: Message,
  ): void {
    this.server.to(message.room).emit('send-message', message);
    this.usersService.storeMessage(message)
  }

  afterInit(server: Server) {
    this.logger.log('Init');
  }

  handleDisconnect(client: Socket) {
    this.logger.log(`Client disconnected: ${client.id}`);
  }

  handleConnection(client: Socket, ...args: any[]) {
    this.logger.log(`Client connected: ${client.id}`);
    this.logger.log(client.data)
    this.logger.log(client.request.headers);
    this.logger.log(args);
  }
}
