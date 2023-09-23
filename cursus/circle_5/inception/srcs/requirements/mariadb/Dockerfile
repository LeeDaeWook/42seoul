FROM alpine:3.18.0

COPY ./conf/my.cnf /etc/my.cnf
COPY ./tools/mariadb_entry.sh /tmp/mariadb_entry.sh

RUN apk add --no-cache \
	mariadb \
	# mariadb-common \
	mariadb-server-utils \
	mariadb-client \
	&& apk add openrc \ 
	&& apk update \
	&& apk upgrade \
	&& chown -R mysql:mysql /var/lib/mysql \
	&& chmod 777 /var/lib/mysql

RUN mkdir -p /run/mysqld && mkdir -p /var/lib/mysql
RUN chmod +x /tmp/mariadb_entry.sh

ENTRYPOINT ["sh", "/tmp/mariadb_entry.sh"]

EXPOSE 3306