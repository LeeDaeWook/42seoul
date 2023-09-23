FROM alpine:3.18.0

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/nginx_entry.sh /tmp/nginx_entry.sh

# package install
RUN apk update \
	&& apk upgrade \
	&& apk add --no-cache \
	nginx \
	openssl

RUN mkdir -p /etc/nginx/ssl
RUN chmod 700 /etc/nginx/ssl
# RUN mkdir -p /var/www/

# SSL settings
RUN openssl req -newkey rsa:2048 \
	-days 365 \
    -x509 \ 
	-nodes \
	-subj '/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=daewoole' \
	-keyout /etc/nginx/ssl/localhost.daewoole.key \
	-out /etc/nginx/ssl/localhost.daewoole.crt

RUN chmod +x /tmp/nginx_entry.sh

ENTRYPOINT [ "sh", "/tmp/nginx_entry.sh" ]

EXPOSE 443