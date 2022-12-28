import { Injectable } from "@nestjs/common";
import { Server, Socket } from "socket.io";
import { JoinRoomDto } from "./dto/join-room.dto";

@Injectable()
export class RoomsService {
    private rooms: Set<string> = new Set();

    join(room: JoinRoomDto, client: Socket) {
        this.rooms.add(room.name);
        client.join(room.name);
    }

    sendMessage(server: Server, message: any, clientId: string) {
        if (server.of("/").adapter.rooms.get(message.room)?.has(clientId))
            server.to(message.room).emit("send-message", message.body);
    }

    findAll(server: Server, client: Socket) {
        const list = Array.from(this.rooms.keys());
        console.log(this.rooms);
        server.to(client.id).emit("find-all-rooms", { list });
    }

    findOne(name: string) {
        return Array.from(this.rooms.keys()).filter((a) => a === name);
    }

    leave(room: JoinRoomDto, client: Socket, server: Map<string, Set<string>>) {
        if (server.get(room.name).size < 2) this.rooms.delete(room.name);
        client.leave(room.name);
    }
}
