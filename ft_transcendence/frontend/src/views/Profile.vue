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
			qr_src: '',
			two_auth_text: ''
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
			if (this.user.twoFactorEnabled) {
				this.checked = true;
				this.two_auth_text = '2fa Enabled';
			}
			else
				this.two_auth_text = 'Enable 2fa';
		},
		async create_verification() {
			// alert(this.value);
			// '+' == %2b
			if (this.checked) {
				return ;
			}
			this.show = !this.show;
			this.checked = !this.checked;
			const api = `http://localhost:5050/auth/generate-qr`; 
			this.qr_src = await this.axios.get(api, { withCredentials: true });
		},
		verify_code() {
			if (this.user.twoFactorEnabled)
				return ;
			let api = 'http://localhost:5050/auth/verify-g-code';
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
	<div class="card">
		<div class="flex align-items-center text-center justify-content-center flex-wrap card-container" style="min-height: 320px;">
			<div class="image-cropper">
				<img :src="avatar" style="" class="profile-pic">
			</div>
			<div class="col-12 text-center">
				<Button  icon="pi pi-upload" iconPos="right" class="p-button-rounded p-button-outlined" />	
			</div>
			<div  class="col-12 text-center">
				<p>Welcome, {{this.user.username}}!</p>
			</div>
			
		</div>
		<div class="flex align-items-center text-center justify-content-center flex-wrap card-container">
			<div class="col-12" style="margin: 0 auto;">
				<Tag>{{this.two_auth_text}}</Tag>
			</div>
			<div class="col-12">
				<InputSwitch v-model="checked" @click="create_verification" />
			</div>
		</div>
		
		<!-- <div class="telephone-nbr">
			<InputMask v-if="checked" v-model="value" mask="+99 9999999999" placeholder="Insert telephone number" />
			<Button v-if="checked" @click="create_verification" icon="pi pi-check" iconPos="right" />
		</div> -->
		<div class="flex align-items-center justify-content-center flex-wrap card-container" style="min-height: 320px;">
			<div v-html="this.qr_src.data" class="qr-img text-center">
			</div>
			<p v-if="!checked && this.user.twoFactorEnabled"> Scan this QrCode with your google Auth app, then use the code generated below to confirm!</p>
		</div>
		
		<div class="text-center" v-if="show" style="" >
			<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
			<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
		</div>
	</div>
</template>

<style lang="scss">


.qr-img > a > img {
	width: 200px;	
}

.telephone-nbr {
	position: relative;
	top: 115px;
	left: 10px;
}

.image-cropper {
	margin: 0 auto;
    width: 200px;
    height: 200px;
    position: relative;
    overflow: hidden;
    border-radius: 50%;
	border: 3px solid rgb(238, 0, 83);
}
.profile-pic {
  display: inline;
  margin: 0 auto;
  margin-left: -25%; //centers the image
  height: 100%;
  width: auto;

}

</style>