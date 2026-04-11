FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y nginx openssl

RUN openssl req -new -newkey rsa:4096 -x509 -sha512 -days 365 -nodes  \
	-subj "/C=FR/ST=Paris/O=42/CN=davli.42.fr"  \
	-out /etc/ssl/certs/nginx.crt  \
	-keyout /etc/ssl/private/nginx.key

COPY ./conf/nginx.conf /etc/nginx/conf.d

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
