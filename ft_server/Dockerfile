FROM debian:buster

RUN apt update
RUN apt install -y curl gnupg2 ca-certificates lsb-release
RUN wget http://nginx.org/keys/nginx_signing.key
RUN apt-key add nginx_signing.key
RUN echo "deb http://nginx.org/packages/debian `lsb_release -cs` nginx" | sudo tee /etc/apt/sources.list.d/nginx.list
RUN sudo apt update
RUN sudo apt install -y nginx
RUN systemctl start nginx

CMD ["nginx", "-g", "daemon off;"]