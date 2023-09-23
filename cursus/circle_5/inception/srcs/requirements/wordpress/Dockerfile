FROM alpine:3.16.3

HEALTHCHECK --interval=1s --timeout=2s --start-period=10s --retries=20 \
	CMD wp core is-installed --allow-root --path=/var/www || exit 1

RUN apk update && apk upgrade \
	&& apk add bash \
	php8 \ 
	php8-fpm \ 
	php8-mysqli \
	php8-opcache \
	php8-gd \
	php8-zlib \
	php8-curl \
	php8-bcmath \
	php8-ctype \
	php8-iconv \
	php8-intl \
	php8-json \
	php8-mbstring \
	php8-mysqlnd \
	php8-openssl \
	php8-pdo \
	php8-pdo_mysql \
	php8-pdo_pgsql \
	php8-pdo_sqlite \
	php8-phar \
	php8-posix \
	php8-session \
	php8-soap \
	php8-xml \
	php8-zip \
	libmcrypt-dev \
	libltdl \
	lighttpd \
	curl 

RUN adduser -u 82 -D -S -G www-data www-data
RUN chown -R www-data:www-data /var/www

COPY ./conf/www.conf /etc/php8/php-fpm.d/www.conf
COPY ./conf/wp-config.php /tmp/wp-config.php
COPY ./tools/wordpress_entry.sh /tmp/wordpress_entry.sh

RUN chmod +x /tmp/wordpress_entry.sh

ENTRYPOINT [ "sh", "/tmp/wordpress_entry.sh" ]

EXPOSE 9000