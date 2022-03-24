import { Logger } from '@nestjs/common';
import { WebSocketGateway, SubscribeMessage, MessageBody, WebSocketServer, ConnectedSocket, OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect } from '@nestjs/websockets';
import { RoomsService } from './rooms.service';
import { JoinRoomDto } from './dto/join-room.dto';
import { Server, Socket } from 'socket.io';

@WebSocketGateway({
  cors: {
    origin: '*',
  },
})
export class RoomsGateway implements OnGatewayInit, OnGatewayConnection, OnGatewayDisconnect {
  @WebSocketServer() server: Server;

  private logger: Logger = new Logger('RoomsGateway');

  constructor(private readonly roomsService: RoomsService) {}

  @SubscribeMessage('join-room')
  create(
    @MessageBody() joinRoomDto: JoinRoomDto,
    @ConnectedSocket() client: Socket
  ) {
    this.roomsService.join(joinRoomDto, client)
  }

  @SubscribeMessage('send-message')
  send(
    @MessageBody() message: any,
    @ConnectedSocket() client: Socket
  ) {
    this.roomsService.sendMessage(this.server, message, client.id)
  }

  @SubscribeMessage('find-all-rooms')
  findAll(
      @ConnectedSocket() client: Socket
  ) {
    this.roomsService.findAll(this.server, client);
  }

  @SubscribeMessage('find-one-room')
  findOne(@MessageBody() name: string) {
    return this.roomsService.findOne(name);
  }

  // @SubscribeMessage('updateRoom')
  // update(@MessageBody() updateRoomDto: any) {
  //   return this.roomsService.update(updateRoomDto.id, updateRoomDto);
  // }

  @SubscribeMessage('leave-room')
  leave(
    @MessageBody() joinRoomDto: JoinRoomDto,
    @ConnectedSocket() client: Socket
  ) {
    this.roomsService.leave(joinRoomDto, client, this.server.of("/").adapter.rooms);
  }

  afterInit(server: Server) {
    this.logger.log('Init');
  }

  handleDisconnect(client: Socket) {
    this.logger.log(`Client disconnected: ${client.id}`);
  }

  handleConnection(client: Socket, ...args: any[]) {
    this.logger.log(`Client connected: ${client.id}`);
    this.findAll(client)
    this.logger.log(client.data)
    this.logger.log(client.request.headers);
    this.logger.log(args);
  }
}
