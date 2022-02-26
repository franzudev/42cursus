<script lang="ts">
import { RouterView } from "vue-router"

export default {
  data() {
    return {
      nestedMenuitems: [
        {
          label: 'Profile',
          icon: 'pi pi-fw pi-user'
        },
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
      ]
    }
  }
}
</script>

<template>
  <header>
    <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="125" height="125" />
    <Menubar :model="nestedMenuitems">
      <template #end>
        <span class="p-input-icon-left">
          <i class="pi pi-search" />
          <InputText type="text" placeholder="Search" />
        </span>
      </template>
    </Menubar>
  </header>

  <RouterView />
</template>