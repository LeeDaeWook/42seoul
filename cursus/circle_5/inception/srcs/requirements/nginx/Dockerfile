FROM debian

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/entry_point.sh /tmp/entry_point.sh

# 이미지 생성 과정에서 실행할 명령어
RUN apt-get update && apt-get install -y nginx

# SSL settings
RUN openssl req -newkey rsa:2048 \
	-days 365 \
    -x509 \ 
	-nodes \
	-subj '/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=daewoole' \
	-keyout /etc/nginx/ssl/localhost.daewoole.key \
	-out /etc/nginx/ssl/localhost.daewoole.crt

EXPOSE 443
    
# 이미지 생성 명령어 (현 파일과 같은 디렉토리에서)
# docker build -t {이미지명} .

# 컨테이너 생성 & 실행 명령어
# docker run --name {컨테이너명} -v $(pwd):/usr/src/app -p 5000:5000 {이미지명}