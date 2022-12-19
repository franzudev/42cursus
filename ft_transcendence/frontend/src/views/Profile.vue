<script lang="ts">
import { defineComponent, reactive } from "vue";
import {createApp} from 'vue';
import PrimeVue from 'primevue/config';
import {PrimeIcons} from 'primevue/api';
import 'primeicons/primeicons.css';
import InputSwitch from 'primevue/inputswitch';
import InputMask from 'primevue/inputmask';
import Button from 'primevue/button';
import Tag from 'primevue/tag';
import Avatar from 'primevue/avatar';
import axios from 'axios';
import Card from 'primevue/card';
import Dialog from 'primevue/dialog';
import Knob from 'primevue/knob';

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
            two_auth_text: '',
			knob_value: 0,
			displayResponsive: false,
			displayModalStats: false,
			displayModalAchievements: false,
			displayModal2FA: false,
			displayModalFriends: false,
			displayModalHistory: false,
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
			this.openResponsive();
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
        },
		openResponsive() {
            this.displayResponsive = true;
        },
        closeResponsive() {
            this.displayResponsive = false;
        },
		openModalStats() {
            this.displayModalStats = true;
        },
		openModalAchievements() {
			this.displayModalAchievements = true;
		},
		openModal2FA() {
			this.displayModal2FA = true;
			this.create_verification();
		},
		openModalFriends() {
			this.displayModalFriends = true;
		},
		openModalHistory() {
			this.displayModalHistory = true;
		}
    },
    created() {
        this.get_image();
    }
}
</script>
<template>
<div class="grid grid-nogutter flex align-items-center justify-content-center" style="padding: 30px;">
    <div class="sm:col-12 md:col-6 lg:col-4" >
        <div class="card my-card">
			<div class="grid">
				<!-- <div class="sm:col-12 md:col-4 lg:col-4 flex align-content-evenly flex-wrap card-container"  style="padding: 60px;">
					<div class="flex align-content-evenly flex-wrap card-container">
							<Button class="flex align-items-center justify-content-center" label="Statistics" icon="pi pi-chart-line" @click="openModal" />
							<Dialog v-model:visible="displayModal" :breakpoints="{'960px': '75vw'}" style="width: '100vw'; max-width: '500px';">
								<Knob modelValue="60" v-model="knob_value" :min="0" :max="100" valueColor="green" rangeColor="black" readonly="" :size="200" textColor="white" />
								<Knob modelValue="40" v-model="knob_value" :min="0" :max="100" valueColor="red" rangeColor="black" readonly="" :size="200" textColor="white" />
							</Dialog>
					</div>
					<div class="flex align-content-evenly flex-wrap card-container">
						<Button class="flex align-items-center justify-content-center" label="Achievements" icon="pi pi-chart-line" @click="openModalAchievements" />
						<Dialog v-model:visible="displayModalAchievements" :breakpoints="{'960px': '75vw'}" style="width: '100vw'; max-width: '500px';">
							
						</Dialog>
					</div>
				</div> -->
				<div class="sm:col-12 md:col-4 lg:col-12"  style="padding: 60px;">
					<div class="flex align-items-center text-center justify-content-center flex-wrap card-container">
						<div class="image-cropper">
							<img :src="avatar" style="" class="profile-pic">
						</div>
						<div class="col-12" style="padding: 15px;">
							<Button  icon="pi pi-upload" class="p-button-rounded p-button-outlined" />
						</div>
						<div  class="username">
							<p>{{this.user.username}}</p>
						</div>
						<div class="col-12 text-center">
							<p style="color: black;"><i class="pi pi-circle-fill" style="color: green; font-size: 0.7rem;" ></i> Online</p>
						</div>
					</div>
					<div class="flex align-items-center text-center justify-content-center flex-wrap card-container">
						<!-- <div class="col-12" style="margin: 0 auto;">
							<Tag>{{this.two_auth_text}}</Tag>
						</div>
						<div class="col-12">
							<InputSwitch v-model="checked" @click="create_verification" />
							<Dialog v-model:visible="displayResponsive" :breakpoints="{'960px': '75vw'}" style="width: '100vw'; max-width: '500px';">
								<div class="flex align-items-center justify-content-center flex-wrap card-container" style="min-height: 320px;">
									<div v-html="this.qr_src.data" class="qr-img text-center">
									</div>
									<p v-if="!checked && this.user.twoFactorEnabled"> Scan this QrCode with your google Auth app, then use the code generated below to confirm!</p>
								</div>
								<div class="text-center" v-if="show" style="" >
									<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
									<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
								</div>
							</Dialog>
						</div> -->
						<div class="lg:col-2"></div>
						<div class="lg:col-4 sm:col-12" style="margin-top: 20px; margin-bottom: 20px;">
							<Button icon="pi pi-comment" label="MESSAGE" class="p-button-rounded p-button-help" />
						</div>
						<div class="lg:col-4 sm:col-12" style="margin-top: 20px; margin-bottom: 20px;">
							<Button icon="pi pi-comment" label="ADD AS FRIEND" class="p-button-rounded p-button-info" />
						</div>
						<div class="lg:col-2"></div>
						<div class="grid align-items-center text-center lg:justify-content-between sm:justify-content-center" style="width: 100%;">
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-chart-line" class="p-button-rounded p-button-secondary" @click="openModalStats" />
								<Dialog v-model:visible="displayModalStats" :breakpoints="{'960px': '75vw'}" style="width: '100vw'; max-width: '500px';">
									<Knob modelValue="60" v-model="knob_value" :min="0" :max="100" valueColor="green" rangeColor="black" readonly="" :size="200" textColor="black" />
									<Knob modelValue="40" v-model="knob_value" :min="0" :max="100" valueColor="red" rangeColor="black" readonly="" :size="200" textColor="black" />
								</Dialog>
								<p>Stats</p>
							</div>
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-star" class="p-button-rounded p-button-warning" @click="openModalAchievements" />
								<Dialog v-model:visible="displayModalAchievements" :breakpoints="{'960px': '75vw'}" style="width: 100%; max-width: 500px;">
 									<div class="card">
										<div class="grid align-items-center text-center" style="margin-top: 5px; width: 100%;">
											<div class="col-6">
												<img src="https://st2.depositphotos.com/8637214/49529/v/600/depositphotos_495291564-stock-illustration-colorful-simple-flat-pixel-art.jpg" alt="" style="width: 80px; border-radius: 100%;">
											</div>
											<div class="col-6">
												<p>Won a match</p>
											</div>
										</div>
									</div>
									<div class="card">
										<div class="grid align-items-center text-center" style="margin-top: 5px; width: 100%;">
											<div class="col-6">
												<img src="https://t4.ftcdn.net/jpg/01/31/41/99/360_F_131419939_Uh5AUdnNOjGiVEpFgweSWogZMXBDuGwE.jpg" alt="" style="width: 80px; border-radius: 100%;">
											</div>
											<div class="col-6">
												<p>Lost a match</p>
											</div>
										</div>
									</div>
								</Dialog>
								<p>Achievements</p>
							</div>
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-sort-numeric-up" class="p-button-rounded p-button-success" @click="openModal" />
								<p>Level</p>
							</div>
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-users" class="p-button-rounded p-button-info" @click="openModalFriends" />
								<Dialog v-model:visible="displayModalFriends" :breakpoints="{'960px': '75vw'}" style="width: 100%; max-width: 500px;">
 									<div class="card">
										<div class="grid align-items-center text-center" style="margin-top: 5px; width: 100%;">
											<div class="col-6">
												<img src="https://res.cloudinary.com/muhammederdem/image/upload/v1537638518/Ba%C5%9Fl%C4%B1ks%C4%B1z-1.jpg" alt="" style="width: 80px; border-radius: 100%;">
											</div>
											<div class="col-6">
												<p>Borat</p>
											</div>
										</div>
									</div>
								</Dialog>
								<p>Friends</p>
							</div>
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-history" class="p-button-rounded p-button-danger" @click="openModalHistory" />
								<Dialog v-model:visible="displayModalHistory" :breakpoints="{'960px': '75vw'}" style="width: 100%; max-width: 500px;">
 									<div class="card">
										<div class="grid align-items-center text-center" style="margin-top: 5px; width: 100%;">
											<div class="col-6">
												<img src="https://res.cloudinary.com/muhammederdem/image/upload/v1537638518/Ba%C5%9Fl%C4%B1ks%C4%B1z-1.jpg" alt="" style="width: 80px; border-radius: 100%;">
											</div>
											<div class="col-6">
												<p>Won 5 - 4</p>
											</div>
										</div>
									</div>
								</Dialog>
								<p>History</p>
							</div>
							<div class="lg:col-2 sm:col-4 icon-divs">
								<Button icon="pi pi-qrcode" class="p-button-rounded p-button-help" @click="openModal2FA" />
								<Dialog v-model:visible="displayModal2FA" :breakpoints="{'960px': '75vw'}" style="width: '100vw'; max-width: '500px';">
									<div class="flex align-items-center justify-content-center flex-wrap card-container" style="min-height: 320px;">
										<div v-html="this.qr_src.data" class="qr-img text-center">
										</div>
										<p v-if="!checked && this.user.twoFactorEnabled"> Scan this QrCode with your google Auth app, then use the code generated below to confirm!</p>
									</div>
									<div class="text-center" v-if="show" style="" >
										<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
										<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
									</div>
								</Dialog>
								<p>Enable 2fa</p>
							</div>
						</div>
					</div>
					<!-- <div class="flex align-items-center justify-content-center flex-wrap card-container" style="min-height: 320px;">
						<div v-html="this.qr_src.data" class="qr-img text-center">
						</div>
						<p v-if="!checked && this.user.twoFactorEnabled"> Scan this QrCode with your google Auth app, then use the code generated below to confirm!</p>
					</div>
					<div class="text-center" v-if="show" style="" >
						<InputMask v-model="code" mask="999999" placeholder="Insert validation code" />
						<Button @click="verify_code" icon="pi pi-check" iconPos="right" />
					</div> -->
				</div>
			</div>
        </div>
    </div>
    <!-- <div class="sm:col-12 md:col-6 lg:col-6"> -->
        <!-- <div class="card my-card second-card"> -->
			<!-- <div class="followers">
				<h5 title="Followers"><i class="fas fa-users"></i> <span class="followers"> 99</span></h5>
			</div>
			<div class="button">
				<a href="#" class="btn" onmousedown="follow();"> Follow<i class="fas fa-user-plus"></i></a>
			</div> -->
			<!-- <div class="win-donut-chart-block block"> 
				<div class="donut-chart">
					<div id="part1" class="portion-block"><div class="circle"></div></div>
					<div id="part2" class="portion-block"><div class="circle"></div></div>
					<p class="center"><i class="pi pi-thumbs-up" style="font-size: 4rem;"></i></p>
				</div>
			</div>
			<div class="lose-donut-chart-block block"> 
				<div class="donut-chart">
					<div id="part1" class="portion-block"><div class="circle"></div></div>
					<div id="part2" class="portion-block"><div class="circle"></div></div>
					<p class="center"><i class="pi pi-thumbs-down" style="font-size: 4rem;"></i></p>
				</div>
			</div> -->
			<!-- <div class="flex align-items-center text-center justify-content-center flex-wrap card-container">
				<Knob modelValue="60" v-model="knob_value" :min="0" :max="100" valueColor="green" rangeColor="black" readonly="" style="position: relative; margin: auto; top: 400px;" :size="200" textColor="black"></Knob>
				<Knob modelValue="40" v-model="knob_value" :min="0" :max="100" valueColor="red" rangeColor="black" readonly="" style="position: relative; margin: auto; top: 400px;" :size="200" textColor="black"></Knob>
			</div> -->
        <!-- </div> -->
    <!-- </div> -->
</div>
</template>

<style lang="scss">
body {
    background: linear-gradient(#F72585, #B5179E, #7209B7);
}

.card {
    padding: 0 !important;
}
.my-card {
	margin-top: 70px;
    width: 100%;
    // height: 800px;
    border-radius: 10px;
    box-shadow: 0 10px 25px 5px rgba(0, 0, 0, 0.2);
    background: white;
    overflow: hidden;

    .image-cropper {
        margin: auto;
		//margin-top: -100px;
        right: 0;
        left: 0;
        width: 175px;
        height: 175px;
        position: relative;
		// transform: translateY(-50%);
		z-index: 3;
        overflow: hidden;
        border-radius: 50%;
        box-shadow: 0 0 0 5px #F72585,
                inset 0 0 0 5px #B5179E,
                inset 0 0 0 5px #F72585,
                inset 0 0 0 5px #B5179E,
                inset 0 0 0 5px #F72585,;
        background: white;
        animation: mvTop 1.5s;
        img {
            width: 100%;
            height: 100%;
            object-fit: cover;
        }
    }
    .username {
        width: inherit;
        // height: 70px;
		// margin: 20px;
        text-align: center;
        animation: fadeIn 2s ease-in;
        p {
            padding: 5px 20px;
            border-radius: 10px;
            color: black;
            letter-spacing: 0.05em;
            text-decoration: none;
            font-size: 30px;
            transition: all 1s;
            &:hover {
                color: white;
                background: #560BAD;
            }
        }
    }
	.icon-divs {
		// margin-left: 20px;
		margin-top: 10px;
	}
	.icon-divs p {
		color: black;
		margin-top: 10px;
	}
}
// .second-card {
//     width: 100%;
//     height: 800px;
//     background: white;
//     border-radius: 10px;
//     overflow: hidden;

	// .followers {
	// 	color: #E64C65;
	// 	position: relative;
	// 	top: 70px;
	// 	left: 100px;
	// }

	// .button {
	// 	position: relative;
	// 	top: 109px;
	// 	left: -30px;
	// 	width: inherit;
	// 	height: 40px;
	// 	text-align: center;
	// 	outline: none;
	// 	a {
	// 		padding: 5px 20px;
	// 		border-radius: 10px;
	// 		color: #E64C65;
	// 		letter-spacing: 0.05em;
	// 		text-decoration: none;
	// 		font-size: 10px;
	// 		transition: all 1s;
	// 		&:hover {
	// 			color: white;
	// 			background: crimson;
	// 		}
	// 	}
  	// }

	// .win-donut-chart-block {
	// 	position: relative;
	// 	top: 350px;
	// 	right: 170px;

	// 	.donut-chart {
	// 	position: relative;
	// 	width: 200px;
	// 	height: 200px;
	// 	margin: 0 auto 2rem;
	// 	border-radius: 100%
	// 	}
		
	// 	p.center {
	// 		background: #394264;
	// 		position: absolute;
	// 		text-align: center;
	// 		font-size: 28px;
	// 		top:0;
	// 		left:0;
	// 		bottom:0;
	// 		right:0;
	// 		width: 130px;
	// 		height: 130px;
	// 		margin: auto;
	// 		border-radius: 50%;
	// 		line-height: 35px;
	// 		padding: 15% 0 0;
	// 	}
		
	// 	.portion-block {
	// 		border-radius: 50%;
	// 		clip: rect(0px, 200px, 200px, 100px);
	// 		height: 100%;
	// 		position: absolute;
	// 		width: 100%;
	// 	}
	// 	.circle {
	// 		border-radius: 50%;
	// 		clip: rect(0px, 100px, 200px, 0px);
	// 		height: 100%;
	// 		position: absolute;
	// 		width: 100%;
	// 		font-family: monospace;
	// 		font-size: 1.5rem;
	// 	}
		
		
	// 	#part1 {
	// 		transform: rotate(0deg);
	// 	}

	// 	#part1 .circle {
	// 		background-color: rgb(0, 218, 0);
	// 		animation: first 1s 1 forwards;
	// 	}

	// 	@keyframes first {
	// 		from {transform: rotate(0deg);}
	// 		to {transform: rotate(180deg);}
	// 	}
	// }

	// .lose-donut-chart-block {
	// 	position: relative;
	// 	top: 120px;
	// 	left: 190px;

	// 	.donut-chart {
	// 	position: relative;
	// 	width: 200px;
	// 	height: 200px;
	// 	margin: 0 auto 2rem;
	// 	border-radius: 100%
	// 	}
		
	// 	p.center {
	// 		background: #394264;
	// 		position: absolute;
	// 		text-align: center;
	// 		font-size: 28px;
	// 		top:0;
	// 		left:0;
	// 		bottom:0;
	// 		right:0;
	// 		width: 130px;
	// 		height: 130px;
	// 		margin: auto;
	// 		border-radius: 50%;
	// 		line-height: 35px;
	// 		padding: 15% 0 0;
	// 	}
		
	// 	.portion-block {
	// 		border-radius: 50%;
	// 		clip: rect(0px, 200px, 200px, 100px);
	// 		height: 100%;
	// 		position: absolute;
	// 		width: 100%;
	// 	}
	// 	.circle {
	// 		border-radius: 50%;
	// 		clip: rect(0px, 100px, 200px, 0px);
	// 		height: 100%;
	// 		position: absolute;
	// 		width: 100%;
	// 		font-family: monospace;
	// 		font-size: 1.5rem;
	// 	}
		
	// 	#part2 {
	// 		transform: rotate(180deg);
	// 	}

	// 	#part2 .circle {
	// 		background-color: rgb(250, 7, 7);
	// 		animation: second 1s 1 forwards 1s;
	// 	}

	// 	@keyframes second {
	// 		from {transform: rotate(360deg);}
	// 		to {transform: rotate(180deg);}
	// 	}
	// }
// }
.qr-img > a > img {
    width: 200px;
}
</style>