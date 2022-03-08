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

const rooms = ref(null);
const chatRoomService = ref(new ChatRoomService());

</script>


<template>
    <div class="sidebar">
        <li v-for="room in rooms">
            <!-- <ChatRoomItem /> -->
         {{   room.name }}
        </li>
    </div>
</template>

<style lang="scss">
.sidebar {
    width: 200px;
    height: calc(100vh - 69px);
    background-color: black;
}
</style>
