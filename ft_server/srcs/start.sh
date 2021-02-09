#!/bin/sh

GREEN='\033[0;32m'
NC='\033[0m'

service php7.3-fpm start
echo "[ ${GREEN}ok${NC} ] Starting PHP service${NC}"
service mysql start
mysql -uroot -e "CREATE DATABASE wordpress;"
mysql -uroot -e "GRANT ALL PRIVILEGES ON wordpress.* TO "root"@"localhost";"
mysql -uroot -e "FLUSH PRIVILEGES;"

service nginx start
echo "[ ${GREEN}ok${NC} ] Starting NGINX service${NC}"

tail -f /dev/null