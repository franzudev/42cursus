import { createApp, reactive } from 'vue'
import { createPinia } from 'pinia'

import './assets/styles/layout.scss';

import App from './App.vue';
import router from './router';
import PrimeVue from 'primevue/config';
import InputText from 'primevue/inputtext';
import Menubar from 'primevue/menubar';
import ToggleButton from 'primevue/togglebutton';
import InputSwitch from 'primevue/inputswitch';
import InputMask from 'primevue/inputmask';
import Button from 'primevue/button';


import * as Vue from 'vue' // in Vue 3
import axios from 'axios'
import VueAxios from 'vue-axios'

const app = createApp(App)
app.config.globalProperties.$appState = reactive({ theme: 'lara-dark-indigo', darkTheme: true });

app.use(PrimeVue, { ripple: true, inputStyle: 'outlined' });
app.use(createPinia())
app.use(router);
app.use(VueAxios, axios);
app.component('InputText', InputText);
app.component('Menubar', Menubar);
app.component('ToggleButton', ToggleButton);
app.component('InputSwitch', InputSwitch);
app.component('InputMask', InputMask);
app.component('Button', Button);

app.mount('#app')

