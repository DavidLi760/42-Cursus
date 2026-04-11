FROM debian:bullseye

RUN	apt-get update && \
	apt-get install -y	\
	curl \
	mariadb-client \
	php7.4 \
	php7.4-fpm \
	php7.4-curl \
	php7.4-mysql

RUN mkdir -p /run/php
RUN	mkdir -p /var/www/html

RUN	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/setup.sh"]

CMD ["php-fpm7.4", "-F"]
