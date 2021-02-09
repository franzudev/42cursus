FROM debian:buster

# Update repository dependencies and
RUN apt update
RUN	apt install -y gnupg2 ca-certificates lsb-release wget vim openssl

RUN	wget http://nginx.org/keys/nginx_signing.key
RUN	apt-key add nginx_signing.key
RUN echo "deb http://nginx.org/packages/debian `lsb_release -cs` nginx" | tee /etc/apt/sources.list.d/nginx.list

RUN	apt update
RUN	apt install -y nginx && \
	apt install -y mariadb-server mariadb-client && \
	apt install -y php-fpm php-mysql php-cli php-json php-mbstring

RUN mkdir /var/www/
RUN wget -c https://wordpress.org/latest.tar.gz -O - | tar -xz -C /var/www/
COPY /srcs/wp-config.php /var/www/wordpress/
RUN chown -R $USER:www-data /var/www/wordpress
RUN chmod g+w /var/www/wordpress/wp-content
RUN chmod -R g+w /var/www/wordpress/wp-content/themes
RUN chmod -R g+w /var/www/wordpress/wp-content/plugins
RUN wget -c https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz -O - | tar -xz -C /var/www
WORKDIR /var/www
RUN mv phpMyAdmin-5.0.4-english phpmyadmin

WORKDIR /
RUN openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=mydomain.com" -addext "subjectAltName=DNS:mydomain.com" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt;
COPY /srcs/nginx.conf /etc/nginx/conf.d/default.conf
COPY /srcs/start.sh /start.sh
RUN chmod +x /start.sh

CMD ["./start.sh"]
