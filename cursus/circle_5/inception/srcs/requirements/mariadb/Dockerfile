FROM alpine:3.18.0

COPY ./conf/my.cnf /etc/my.cnf
COPY ./tools/mariadb_entry.sh /tmp/mariadb_entry.sh

RUN apk add --no-cache \
	mariadb \
	mariadb-common \
	mariadb-server-utils \
	mariadb-client \
	&& apk add openrc && apk update && apk upgrade \
	&& chown -R mysql:mysql /var/lib/mysql \
	&& chmod 755 /var/lib/mysql

RUN mkdir -p /run/mysqld && mkdir -p /var/lib/mysql
RUN chmod +x /tmp/mariadb_entry.sh

ENTRYPOINT ["sh", "/tmp/mariadb_entry.sh"]

EXPOSE 3306

# # 이미지 생성 과정에서 복사할 파일 지정
# COPY ./tools/entry_point.sh /tmp/entry_point.sh
# COPY ./conf/my.cnf /etc/my.cnf

# # 이미지 생성 과정에서 실행할 명령어
# RUN apt-get update -y && \
#     apt-get -y install mariadb-server mariadb-client

# RUN mkdir -p /run/mysqld && mkdir -p /var/lib/mysql
# RUN chmod +x /tmp/entry_point.sh

# ENTRYPOINT [ "sh", "/tmp/entry_point.sh" ]

# EXPOSE 3306

# # 이미지 생성 명령어 (현 파일과 같은 디렉토리에서)
# # docker build -t {이미지명} .

# # 컨테이너 생성 & 실행 명령어
# # docker run --name {컨테이너명} -v $(pwd):/usr/src/app -p 5000:5000 {이미지명}