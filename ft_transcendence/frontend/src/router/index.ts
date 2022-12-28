import HomeView from '@/views/HomeView.vue'
import { createRouter, createWebHistory } from 'vue-router'
import axios from 'axios'

const router = createRouter({
    history: createWebHistory(import.meta.env.BASE_URL),
    routes: [
        {
            path: '/',
            name: 'home',
            component: HomeView
        },
        {
            path: '/logged',
            name: 'login-succeed',
            component: HomeView
        },
        {
            path: '/about',
            name: 'about',
            // route level code-splitting
            // this generates a separate chunk (About.[hash].js) for this route
            // which is lazy-loaded when the route is visited.
            component: () => import('@/views/AboutView.vue')
        },
        {
            path: '/chat',
            name: 'chat',
            component: () => import('@/views/ChatView.vue')
        },
        {
            path: '/profile',
            name: 'profile',
            component: () => import('../views/Profile.vue')
        },
        {
            path: '/login',
            name: 'login',
            component: () => import('../views/Login.vue')
        },
        {
            path: '/validation_code',
            name: 'validation_code',
            component: () => import('../views/ValidationCode.vue')
        }
    ]
})

async function createUserAccess() {
    const is_auth = await axios.get('http://localhost:5050/auth/whoami', {withCredentials: true}).then((res) => {
        return res.data
    })
        .catch((err) => {
            return err.data
        })

    return is_auth
}

// router.beforeEach(async (to, from) => {
// let logged_in = false;
// const is_auth = await createUserAccess();

// if (is_auth == 'KO') {
//   logged_in = false;
// }
// else
//   logged_in = true;

//   if (!logged_in && to.name !== 'login') {
//     return {name : 'login'}
//   }

// // console.log(logged_in);
// //   // to and from are both route objects. must call `next`.
// //   return false;
// })

export default router
