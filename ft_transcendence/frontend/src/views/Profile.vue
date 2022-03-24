<script>
import { defineComponent, reactive } from "vue";
import {createApp} from 'vue';
import PrimeVue from 'primevue/config';
import {PrimeIcons} from 'primevue/api';
import InputSwitch from 'primevue/inputswitch';
import InputMask from 'primevue/inputmask';
import Button from 'primevue/button';
import Tag from 'primevue/tag';
import Avatar from 'primevue/avatar';
import axios from 'axios';


export default {
	data() {
		return {
			checked: false,
			show: false,
			value: '',
			code: '',
			avatar: '',
			user: {}, 
			qr_src: ''
		}
	},
	methods: {
		async get_image()
		{
			const api = 'http://localhost:5050/users/me';
			const result = await this.axios.get(api, { withCredentials: true });
			this.user = result.data;
			console.log(this.user);
			this.avatar = result.data.avatar;
			console.log(this.avatar);
		},
		async create_verification() {
			// alert(this.value);
			// '+' == %2b
			this.show = !this.show;
			this.checked = !this.checked;
			const api = `http://localhost:5050/auth/generate_qr`; 
			this.qr_src = await this.axios.get(api, { withCredentials: true });
		},
		verify_code() {
			let api = 'http://localhost:5050/auth/verify_g_code';
			let number_to_send = '%2b' + this.value.substr(1,2) + this.value.substr(4);
			let code_to_send = this.code;
			this.axios.get(api + '?code=' + code_to_send, { withCredentials: true }).then((response) => {
				console.log(response);
				if (response.data == 'approved')
					alert('Number verified!');
				else
					alert('Wrong code, try again');
			})
		}
	},
	created() {
		this.get_image();
	}
}


</script>


<template>
	<div style="">
		<!-- <Button label="Get image" @click="get_image" v-model="image" /> -->
		<Avatar size="xlarge" style="left: 10px; top:10px;">
			<img :src="avatar" >
		</Avatar>
	</div>
	<div style="position: relative; top: 100px; left: 10px;">
		<Tag value="Abilita autenticazione a due fattori"></Tag>
	</div>
	<div class="check-btn">
		<InputSwitch v-model="checked" @click="create_verification" />
	</div>
	<!-- <div class="telephone-nbr">
		<InputMask v-if="checked" v-model="value" mask="+99 9999999999" placeholder="Insert telephone number" />
		<Button v-if="checked" @click="create_verification" icon="pi pi-check" iconPos="right" />
	</div> -->
	<div v-html="this.qr_src.data" style="margin-top:150px"></div>
	<div v-if="show" style="position: relative; top: 120px; left: 10px;" >
		<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
		<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
	</div>
</template>

<style lang="scss">

.telephone-nbr {
	position: relative;
	top: 115px;
	left: 10px;
}

.check-btn {
	position: relative;
	top: 110px;
	left: 10px;
}

</style>