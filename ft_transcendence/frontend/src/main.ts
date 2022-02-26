import { createApp, reactive } from 'vue'
import { createPinia } from 'pinia'

import './assets/styles/layout.scss';

import App from './App.vue';
import AppWrapper from './AppWrapper.vue';
import router from './router';
import PrimeVue from 'primevue/config';
import InputText from 'primevue/inputtext';
import Menubar from 'primevue/menubar';

const app = createApp(AppWrapper)
app.config.globalProperties.$appState = reactive({ theme: 'lara-light-indigo', darkTheme: false });

app.use(createPinia())
app.use(router);
app.use(PrimeVue);
app.component('InputText', InputText);
app.component('Menubar', Menubar);
app.component('App', App);



app.mount('#app')

