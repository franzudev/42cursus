#!/bin/sh

GREEN='\033[0;32m'
NC='\033[0m'

service mysql start
mysql -uroot -e "CREATE DATABASE wordpress;"
mysql -uroot -e "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';"
mysql -uroot -e "GRANT ALL PRIVILEGES ON wordpress.* TO \"wordpress\"@\"localhost\" with GRANT OPTION;"
mysql -uroot -e "FLUSH PRIVILEGES;"

service php7.3-fpm start
echo "[ ${GREEN}ok${NC} ] Starting PHP service${NC}"

service nginx start

bash