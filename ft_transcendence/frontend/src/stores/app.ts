import { defineStore } from 'pinia'
import { useStorage } from "@vueuse/core"


export const useAppStore = defineStore({
    id: 'app',
    state: () => ({
        darkTheme: useStorage('darkTheme', true)
    }),
    getters: {
        isDark: (state) => state.darkTheme,
        themeColor: (state) => state.darkTheme ? "dark" : "light"
    },
    actions: {
        setTheme(value: boolean) {
            const themeElement: HTMLElement = document.getElementById('theme-link') as HTMLElement
            if (themeElement.getAttribute('href')!.includes(this.themeColor))
                themeElement.setAttribute('href', themeElement.getAttribute('href')!.replace(this.themeColor, this.isDark ? "light" : "dark"))
            else
                themeElement.setAttribute('href', themeElement.getAttribute('href')!.replace("dark", "light"))
            this.darkTheme = value
        }
    }
})
