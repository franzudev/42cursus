<script setup lang="ts">
import { defineComponent, reactive, onBeforeMount, onMounted } from "vue";
import { useAppStore } from "@/stores/app";
import SideBar from "@/components/commons/SideBar/SideBar.vue";
import { ref } from 'vue';
import HelloWorld from '../components/HelloWorld.vue';
import AdvancedChat, { type Messages } from 'vue-advanced-chat';
import type { Room, Rooms, Message, LastMessage, MessageAction, MessageActions } from 'vue-advanced-chat';
import socketio from 'socket.io-client'

import 'vue-advanced-chat/dist/vue-advanced-chat.css';

// type room = {
// 	id: number;
// 	name: string;
// 	description: string;
// 	image: string;
// };


const socket = socketio('http://localhost:5050');
const visible = ref(true);
// const roomSelected = ref({ id: 0, "name": "", "description": "", "image": "" })
// const isSelected = ref(false);
// let chats = [];

onMounted(() => {
	socket.emit('find-all-rooms', (response: string[]) => {
		console.log(response.values);
		for (let i = 0; i < response.length; i++) {
			let tempRoom: Room = {
				roomId: i + 1,
				roomName: response[i],
				avatar: '/src/assets/images/avatar/amyelsner.png',
				unreadCount: 0,
				users: [{
					_id: 1,
					username: 'Mpezzull',
					avatar: '/src/assets/images/avatar/annafali.png',
					status: {
						state: 'online',
						lastChanged: 'today, 14:30'
					}
				},
				{
					_id: 2,
					username: 'Ffrancoi',
					avatar: '/src/assets/images/avatar/amyelsner.png',
					status: {
						state: 'online',
						lastChanged: '14 July, 20:00'
					}
				}],
				typingUsers: []

			};
			// rooms.value.push(new Room())
			rooms[i] = tempRoom;
		}
	});
})

// function fillRoom(roomChild: room) {
// 	console.log(roomChild.description);
// 	roomSelected.value = roomChild;
// 	isSelected.value = true;
// }



const rooms: Rooms = reactive([]);
// [
// 	{
// 		roomId: 1,
// 		roomName: 'Room 2',
// 		avatar: '/src/assets/images/avatar/amyelsner.png',
// 		unreadCount: 0,
// 		index: 3,
// 		lastMessage: {
// 			content: 'Last message received',
// 			senderId: 1234,
// 			username: 'John Doe',
// 			timestamp: '10:20',
// 			saved: true,
// 			distributed: false,
// 			seen: false,
// 			new: true
// 		},
// 		users: [
// 			{
// 				_id: 1234,
// 				username: 'John Doe',
// 				avatar: '/src/assets/images/avatar/annafali.png',
// 				status: {
// 					state: 'online',
// 					lastChanged: 'today, 14:30'
// 				}
// 			},
// 			{
// 				_id: 4321,
// 				username: 'John Snow',
// 				avatar: '/src/assets/images/avatar/amyelsner.png',
// 				status: {
// 					state: 'offline',
// 					lastChanged: '14 July, 20:00'
// 				}
// 			}
// 		],
// 		typingUsers: [4321]
// 	} as Room
// ]);
const messages = ref([
	{
		_id: 7890,
		indexId: 12092,
		content: 'Message 1',
		senderId: 1,
		username: 'John Doe',
		avatar: '/src/assets/images/avatar/amyelsner.png',
		date: '13 November',
		timestamp: '10:20',
		system: false,
		saved: true,
		files: [
			{
				name: 'My File',
				size: 67351,
				type: 'png',
				audio: false,
				url: '/src/assets/images/avatar/amyelsner.png',
				preview: '/src/assets/images/avatar/amyelsner.png',
				progress: 99
			}
		]
	} as Message
] as Messages);
const currentUserId = ref(1);
const theme = ref("dark");

function sendMessage(message: Message, id: Number) {
	console.log("sendMessage");

	const newMessages: Messages = [];
	for (let i = 0; i < messages.value.length; i++)
	{
		// message._id = ;
		newMessages.push(messages.value[i]);
		console.log(messages.value);
	}
	newMessages.push(message);

	// console.log(newMessages);
	messages.value = newMessages;

}
</script>


<template>
	<div style="width: 100%; display: flex;">
		<!-- <SideBar @selectedRoom="fillRoom" />
		<div v-if="isSelected" class="p-component p-menubar" style="width: 100%; height: 8vh;">
			<Button class="p-button-rounded p-button-raised p-button-text">ADD USER</Button>
			<div
				style="width:85%; text-align:center; "
			>{{ roomSelected.name }} : {{ roomSelected.description }}</div>
			<div>Options dropdown</div>
		</div>-->
		<AdvancedChat
			@send-message="sendMessage"
			:roomsLoaded="true"
			:messagesLoaded="true"
			rooms-order="asc"
			:current-user-id="currentUserId"
			:room-info-enabled="true"
			:rooms="rooms"
			:messages="messages"
			height="calc(100vh - 69px)"
		></AdvancedChat>
	</div>
</template>

<style>
</style>