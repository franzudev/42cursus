<script>
import { defineComponent, reactive } from "vue";
import {createApp} from 'vue';
import PrimeVue from 'primevue/config';
import {PrimeIcons} from 'primevue/api';
import InputSwitch from 'primevue/inputswitch';
import InputMask from 'primevue/inputmask';
import Button from 'primevue/button';

export default {
	data() {
		return {
			code: ''
		}
	},
	methods: {
		verify_code() {
			const queryString = window.location.search;
			const urlParams = new URLSearchParams(queryString);
			const username = urlParams.get('username');

			const api = 'http://localhost:5050/auth/verify_login_2fa';
			const code_to_send = this.code;
			this.axios.get(api + '?username=' + username + '&code=' + code_to_send, { withCredentials: true }).then((response) => {
				console.log(response);
				if (response.data == 'approved')
					alert('Number verified!');
				else
					alert('Wrong code, try again');
			})
		}
	}
}


</script>


<template>
	<div style="margin: 0; position: absolute; top: 50%; left: 50%; -ms-transform: translate(-50%, -50%); transform: translate(-50%, -50%);">
		<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
		<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
	</div>
</template>

<style lang="scss">

</style>
