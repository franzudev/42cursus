<script setup lang="ts">
import { onBeforeMount, reactive, ref } from "vue"
import { useAppStore } from "./stores/app"
import { RouterLink, RouterView } from "vue-router"

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
          }
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
      }
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

const store = useAppStore()
const dark = ref(store.isDark)

onBeforeMount(() => {
  if (!dark.value)
    changeTheme()
})

function changeTheme(): boolean {
  store.setTheme(dark.value)
  return dark.value
}

</script>


<template>
  <Menubar :model="menuBar" :exact="true">
    <template #start>
      <RouterLink to="/">
        <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="50" height="50"/>
      </RouterLink>
    </template>
    <template #end>
      <ToggleButton v-on:change="changeTheme" v-model="dark" onIcon="pi pi-moon" style="border-radius: 25px"
                    offIcon="pi pi-sun"/>
    </template>
  </Menubar>
  <main style="width: 100%;">
    <RouterView/>
  </main>
</template>


<style lang="scss">
@import "./assets/styles/layout.scss";

</style>
