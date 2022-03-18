<script setup lang="ts">
import { computed, defineComponent, reactive } from "vue";
import { useAppStore } from "./stores/app";
import { ref } from 'vue';
import { RouterLink, RouterView, useRoute } from "vue-router";
import SideBar from '@/components/commons/SideBar/SideBar.vue'

const menuBar = reactive([
  {
    label: 'Game',
    icon: 'pi pi-fw pi-table',
    items: [
      {
        label: 'New Game',
        icon: 'pi pi-fw pi-user-plus',
        items: [
          {
            label: 'Play with a friend',
            icon: 'pi pi-fw pi-plus'
          },
          {
            label: 'Play with a random user',
            icon: 'pi pi-fw pi-copy'
          },
        ]
      },
      {
        label: 'Watch a game',
        icon: 'pi pi-fw pi-user-edit'
      }
    ]
  },
  {
    label: 'History',
    icon: 'pi pi-fw pi-shopping-cart',
    items: [
      {
        label: 'View',
        icon: 'pi pi-fw pi-list'
      },
      {
        label: 'Search',
        icon: 'pi pi-fw pi-search'
      },
    ]
  },
  {
    label: 'Chat',
    icon: 'pi pi-fw pi-envelope',
    to: '/chat',
    items: [
      {
        label: 'Send a message',
        icon: 'pi pi-fw pi-compass'
      },
      {
        label: 'Join a room',
        icon: 'pi pi-fw pi-map-marker'
      },
      {
        label: 'Create a Room',
        icon: 'pi pi-fw pi-pencil'
      }
    ]
  }
])
const options = reactive(['Dark', 'Light']);
const store = useAppStore()
const darkValue = ref(true);

function changeTheme(): boolean {
  const { isDark, themeColor } = store
  const themeElement: HTMLElement = document.getElementById('theme-link') as HTMLElement;
  themeElement.setAttribute('href', themeElement.getAttribute('href')!.replace(themeColor, isDark ? "light" : "dark"));
  store.setTheme()
  return isDark
}

const moon = "pi pi-moon"
const checked = true
</script>


<template>
  <Menubar :model="menuBar" :exact="true">
    <template #start>
      <RouterLink to="/">
        <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="50" height="50" />
      </RouterLink>
    </template>
    <template #end>
      <ToggleButton v-on:change="changeTheme" v-model="darkValue" onIcon="pi pi-moon" style="border-radius: 25px" offIcon="pi pi-sun" />
      <!-- <InputSwitch v-on:change="changeTheme" v-model="darkValue" :class="moon"/> -->
    </template>
  </Menubar>
  <main style="width: 100%;">
    <RouterView />
  </main>
</template>


<style lang="scss">
@import "./assets/styles/layout.scss";

</style>
