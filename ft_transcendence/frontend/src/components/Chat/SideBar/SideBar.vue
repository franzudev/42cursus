<script setup lang="ts">
import { computed, defineComponent, reactive } from "vue";
import { useAppStore } from "@/stores/app";
import { ref, onMounted } from 'vue';
import ChatRoomService from "@/service/ChatRoomService";

const emit = defineEmits<{
    (e: 'selectedRoom', room: {
        id: number;
        name: string;
        description: string;
        image: string;
    }): void
}>()

onMounted(() => {
    chatRoomService.value.getRooms().then(data => rooms.value = data);
    console.log(rooms.value);
})

function onItemClick(event: MouseEvent, room: {
    id: number;
    name: string;
    description: string;
    image: string;
}) {
    emit("selectedRoom", room);
    SelectRoom(room.id);
}

function SelectRoom(id: number) {
    selected.value = id;
}

function getClass(id: number) {
    if (id == selected.value)
        return "chatroom-item p-highlight";
    return "chatroom-item";
}

function isPublic(id: number)
{
	if (id % 2)
		return true;
	return false;
}

const selected = ref(0);
const rooms = ref([{ id: 0, "name": "", "description": "", "image": "" }]);
const chatRoomService = ref(new ChatRoomService());
</script>


<template>
    <div class="sidebar">
        <div class="p-chatroom-title">Chat Room List</div>
        <div class="p-chatrooms" v-for="room in rooms">
            <!-- <ChatRoomItem /> -->
            <li :class="getClass(room.id)" @click="onItemClick($event, room)">
                <div class="image-container" >
                    <img
                        :src="room.image"
                        :alt="room.name"
                        style="width:30px; height:30px; border-radius: 30px;"
                    > 
                    <span v-if="isPublic(room.id)" style="width:30px; height:10px;" v-badge.success=""/>
                    <span v-else="isPublic(room.id)" style="width:30px; height:10px;" v-badge.danger=""/>
                </div>
                <div style="width:50px; height: 30px;"/>
                <div class="chatroom-list-detail">{{ room.name }}</div>
                <!-- <div>{{ room.description }}</div> -->
            </li>
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
    padding: 0.5rem;
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
