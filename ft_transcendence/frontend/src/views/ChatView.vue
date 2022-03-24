<script setup lang="ts">
import {  reactive, onBeforeMount, onMounted } from "vue";
import { useAppStore } from "@/stores/app";
import { ref } from 'vue';
import Sidebar from "primevue/sidebar";
import socketio from 'socket.io-client'


const socket = socketio('http://localhost:5050');
const visible = ref(true);

onMounted(() => {

})
</script>


<template>
	<div style="width: 100%; display: flex;">
		 <SideBar @selectedRoom="fillRoom" />
		<div v-if="isSelected" class="p-component p-menubar" style="width: 100%; height: 8vh;">
			<Button class="p-button-rounded p-button-raised p-button-text">ADD USER</Button>
			<div
				style="width:85%; text-align:center; "
			>{{ roomSelected.name }} : {{ roomSelected.description }}</div>
			<div>Options dropdown</div>
		</div>
	</div>
</template>

<style>
</style>