import { createApp, reactive } from 'vue'
import { createPinia } from 'pinia'

import './assets/styles/layout.scss';

import App from './App.vue';
import router from './router';
import PrimeVue from 'primevue/config';
import InputText from 'primevue/inputtext';
import Menubar from 'primevue/menubar';

const app = createApp(App)
app.config.globalProperties.$appState = reactive({ theme: 'lara-dark-indigo', darkTheme: true });

app.use(PrimeVue, { ripple: true, inputStyle: 'outlined' });
app.use(createPinia())
app.use(router);
app.component('InputText', InputText);
app.component('Menubar', Menubar);

app.mount('#app')

