<script setup lang="ts">
import { defineComponent, reactive } from "vue";
import { useAppStore } from "./stores/app";

console.log("init")

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

const store = useAppStore()

function changeTheme() {
  const { isDark, themeColor } = store
  const themeElement: HTMLElement = document.getElementById('theme-link') as HTMLElement;
  themeElement.setAttribute('href', themeElement.getAttribute('href')!.replace(themeColor, isDark ? "light" : "dark" ));
  store.setTheme()
}

</script>


<template>
  <header>
    <Menubar :model="menuBar">
      <template #start>
        <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="50" height="50" />
      </template>
    </Menubar>
  </header>
  <button @click="changeTheme">prova</button>

  <RouterView />
</template>


<style lang="scss">
@import "./assets/styles/layout.scss";
</style>
