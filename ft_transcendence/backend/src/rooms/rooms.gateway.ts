import {Logger} from '@nestjs/common';
import {ConnectedSocket, MessageBody, SubscribeMessage, WebSocketGateway, WebSocketServer} from '@nestjs/websockets';
import {RoomsService} from './rooms.service';
import {JoinRoomDto} from './dto/join-room.dto';
import {Server, Socket} from 'socket.io';

@WebSocketGateway({
    cors: {
        origin: '*',
    },
})
export class RoomsGateway {
    @WebSocketServer() server: Server;

    private logger: Logger = new Logger('RoomsGateway');

    constructor(private readonly roomsService: RoomsService) {
    }

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

}
