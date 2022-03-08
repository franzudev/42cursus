export default class ChatRoomService {

	getRooms() {
		return fetch('/data/rooms.json').then(res => res.json()).then(d => d.data);
    }
}