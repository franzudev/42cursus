<template>
    <!-- <Landing v-if="$route.path === '/landing'" @change-theme="changeTheme" />
    <Login v-else-if="$route.path === '/login'" />
    <Error v-else-if="$route.path === '/error'" />
    <NotFound v-else-if="$route.path === '/notfound'" />
    <Access v-else-if="$route.path === '/access'" /> -->
    <App />
</template>

<script lang="ts">
// import EventBus from './AppEventBus';
import App from './App.vue';
// import Landing from './pages/LandingDemo';
// import Login from './pages/Login';
// import Error from './pages/Error';
// import NotFound from './pages/NotFound';
// import Access from './pages/Access';

export default {
    // methods: {
    //     changeTheme(event) {a
    //         let themeElement = document.getElementById('theme-link');
    //         themeElement.setAttribute('href', themeElement.getAttribute('href').replace(this.$appState.theme, event.theme));
    //         this.$appState.theme = event.theme;
    //         this.$appState.darkTheme = event.dark;
    //         EventBus.emit('change-theme', event);

    //         if (event.theme.startsWith('md')) {
    //             this.$primevue.config.ripple = true;
    //         }
    //     }
    // },
    components: {
        App
        // Landing,
        // Login,
        // Error,
        // NotFound,
        // Access
    }
}
</script>

<style lang="scss">
@import './assets/styles/layout.scss';
@import '@/../public/themes/lara-dark-indigo/theme.css';

</style>

