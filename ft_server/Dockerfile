FROM debian:buster

# Update repository dependencies and install basic deps
RUN		apt update
RUN		apt install -y gnupg2 ca-certificates lsb-release wget openssl

# Install nginx server, mysql and php deps
RUN	apt install -y nginx && \
	apt install -y mariadb-server && \
	apt install -y php7.3-fpm php7.3-mysql php7.3-cli php7.3-json php7.3-mbstring

# get wp and phpmyadmin
WORKDIR	/var/www/html
RUN 	wget -c https://wordpress.org/latest.tar.gz -O - | tar -xz -C .
RUN 	wget -c https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz -O - | tar -xz -C .
COPY	/srcs/wp-config.php /var/www/html/wordpress
RUN		mv phpMyAdmin-5.0.4-english phpmyadmin
RUN		cp phpmyadmin/config.sample.inc.php phpmyadmin/config.inc.php
RUN		chown -R www-data:www-data /var/www/*
RUN		chmod -R 755 /var/www/*
RUN		sed -i -e "/blowfish\_secret/s/''/'2CX25NDFJKA_2NFE'/" phpmyadmin/config.inc.php
RUN		mkdir autoindex

WORKDIR /var/www/html/autoindex
RUN touch autoindex is on

WORKDIR /
RUN 	openssl req -x509 -nodes -days 365 -subj "/C=IT/ST=IT/O=Franzu, Inc./CN=localhost" -addext "subjectAltName=DNS:localhost" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.pem

COPY	/srcs/nginx.conf /etc/nginx/sites-available/default
RUN		ln -sfn /etc/nginx/sites-available/default /etc/nginx/sites-enabled/

COPY	/srcs/start.sh /start.sh
COPY	/srcs/autin /usr/bin/autin
RUN		chmod +x /start.sh
RUN		chmod +x /usr/bin/autin

CMD ["./start.sh"]
