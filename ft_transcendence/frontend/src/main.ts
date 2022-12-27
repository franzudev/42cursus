import { createApp, reactive } from 'vue'
import { createPinia } from 'pinia'

import './assets/styles/layout.scss'

import App from './App.vue'
import router from './router'
import PrimeVue from 'primevue/config'
import InputText from 'primevue/inputtext'
import Menubar from 'primevue/menubar'
import ToggleButton from 'primevue/togglebutton'
import InputSwitch from 'primevue/inputswitch'
import BadgeDirective from 'primevue/badgedirective'
import InputMask from 'primevue/inputmask'
import Button from 'primevue/button'
import Avatar from 'primevue/avatar'
import Tag from 'primevue/tag'
import Knob from 'primevue/knob'
import OrderList from 'primevue/orderlist'
import Dialog from 'primevue/dialog'
import axios from 'axios'
import VueAxios from 'vue-axios'

const app = createApp(App)
app.config.globalProperties.$appState = reactive({theme: 'lara-dark-indigo', darkTheme: true})

app.use(PrimeVue, {ripple: true, inputStyle: 'outlined'})
app.use(createPinia())
app.use(router)
app.use(VueAxios, axios)
app.component('InputText', InputText)
app.component('Menubar', Menubar)
app.component('ToggleButton', ToggleButton)
app.component('InputSwitch', InputSwitch)
app.component('Button', Button)

app.directive('badge', BadgeDirective)
app.component('InputMask', InputMask)
app.component('Tag', Tag)
app.component('Avatar', Avatar)
app.component('Knob', Knob)
app.component('Dialog', Dialog)
app.component('OrderList', OrderList)

app.mount('#app')

