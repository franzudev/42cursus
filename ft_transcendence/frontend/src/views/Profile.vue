<script>
import { defineComponent, reactive } from "vue";
import {createApp} from 'vue';
import PrimeVue from 'primevue/config';
import {PrimeIcons} from 'primevue/api';
import InputSwitch from 'primevue/inputswitch';
import InputMask from 'primevue/inputmask';
import Button from 'primevue/button';
import axios from 'axios';


export default {
	data() {
		return {
			checked: false,
			show: false,
			value: '',
			code: ''
		}
	},
	methods: {
		Submit() {
			alert(this.value);
		},
		create_verification() {
			// alert(this.value);
			// '+' == %2b
			this.show = !this.show;
			this.checked = !this.checked;
			let api = 'http://localhost:5050/auth/set_number';
			let number_to_send = '%2b' + this.value.substr(1,2) + this.value.substr(4);
			this.axios.get(api + '?number=' + number_to_send, { withCredentials: true }).then((response) => {
				console.log(response);
			})
		},
		verify_code() {
			let api = 'http://localhost:5050/auth/verify_status';
			let number_to_send = '%2b' + this.value.substr(1,2) + this.value.substr(4);
			let code_to_send = this.code;
			this.axios.get(api + '?number=' + number_to_send + '&code=' + code_to_send, { withCredentials: true }).then((response) => {
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
	<div>
		<p>Abilita autenticazione a due fattori</p>
		<InputSwitch v-model="checked" />
	</div>
	<div>
		<InputMask v-if="checked" v-model="value" mask="+99 9999999999" placeholder="Insert telephone number" />
		<Button v-if="checked" @click="create_verification" icon="pi pi-check" iconPos="right" />
	</div>
	<div v-if="show" >
		<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
		<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
	</div>
</template>

<style lang="scss">

</style>