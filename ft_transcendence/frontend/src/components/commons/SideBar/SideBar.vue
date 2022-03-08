<script setup lang="ts">
import { defineComponent, reactive } from "vue";
import { useAppStore } from "@/stores/app";
import ChatRoomItem from "../ChatRoomItem/ChatRoomItem.vue";
import { ref, onMounted } from 'vue';
import ChatRoomService from "@/service/ChatRoomService";

onMounted(() => {
    chatRoomService.value.getRooms().then(data => rooms.value = data);
    console.log(rooms.value);
})

const rooms = ref([{ "id": Number, "name": String, "description": String, "image": String }]);
const chatRoomService = ref(new ChatRoomService());

</script>


<template>
    <div class="sidebar">
        <div class="p-chatroom-title">Chat Room List</div>
        <div class="p-chatrooms" v-for="room in rooms">
            <!-- <ChatRoomItem /> -->
            <div class="chatroom-item">
                <div class="image-container">
                    <img
                        :src="room.image"
                        :alt="room.name"
                        style="width:30px; height:30px; border-radius: 30px;"
                    />
                </div>
                <div class="chatroom-list-detail ">{{ room.name }} </div>
                <!-- <div>{{ room.description }}</div> -->
            </div>
        </div>
    </div>
</template>

<style lang="scss">
.sidebar {
    width: 250px;
    height: calc(100vh - 69px);
    // background-color: black; moved to theme.css
}

.chatroom-item {
	display: flex;
	align-items: center;
	padding: .5rem;
	width: 100%;

	img {
		width: 75px;
        box-shadow: 0 3px 6px rgba(0, 0, 0, 0.16), 0 3px 6px rgba(0, 0, 0, 0.23);
        margin-right: 1rem;
	}

	.chatroom-list-detail {
		flex: 1 1 0;
	}

	.chatroom-list-action {
		display: flex;
        flex-direction: column;
        align-items: flex-end;
    }
}

@media screen and (max-width: 576px) {
    .chatroom-item {
        flex-wrap: wrap;

        .image-container {
            width: 100%;
            text-align: center;
        }

        img {
            margin: 0 0 1rem 0;
            width: 100px;
        }
    }
}
</style>
