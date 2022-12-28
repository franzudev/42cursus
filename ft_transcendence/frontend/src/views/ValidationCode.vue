<script setup lang="ts">

import { inject } from "vue";

const axios: any = inject('axios');
let code = '';
let error_txt = '';

const verify_code = () => {
  const queryString = window.location.search;
  const username = new URLSearchParams(queryString).get('username');

  const api = 'http://localhost:5050/auth/verify-login-2fa';
  const code_to_send = code;
  axios.get(api + '?username=' + username + '&code=' + code_to_send, {withCredentials: true})
      .then((response: any) => {
        console.log(response);
        if (response.data == 'approved') {
          window.location.href = '/profile';
        } else
          error_txt = 'Wrong code, try again.';
      });
};


</script>


<template>
  <div class="card">
    <div class="flex align-items-center text-center justify-content-center flex-wrap card-container">
      <div class="col-12">
        <p class="text-3xl">Two Factor Authentication Required</p>
      </div>
      <div class="col-12">
        <InputMask v-model="code" mask="999999" placeholder="Insert validation code"/>
        <Button @click="verify_code" icon="pi pi-check" iconPos="right" class="p-button-outlined"/>
      </div>
      <div class="col-12">
        <p style="color: red;">{{ error_txt }}</p>
      </div>
    </div>
  </div>
</template>

<style lang="scss">

</style>
