import Vue from 'vue';
import axios from "axios";

declare module 'vue/types/vue' {
    // Global properties can be declared
    // on the `VueConstructor` interface
    interface VueConstructor {
        // some more augmentation
    }

    // Properties added to Vue interface are added to Vue instance
    interface Vue {
        $appState: { theme: string, darkTheme: boolean }
        $primevue: any
        axios: axios
    }
}
