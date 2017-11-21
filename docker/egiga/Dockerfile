FROM base:latest
	
USER root

RUN apt-get update \
    && usermod -aG sudo tango-cs \
    && apt-get -y install \
    nano \
    git \
    apache2 \
    ufw \
    mysql-server \
    php \
    libapache2-mod-php \
    php-mcrypt \ 
    php-mysql \
    && sudo apt-get -y upgrade mysql-server \
    && cd /var/www/html/ \
    && git clone https://github.com/luciozambon/eGiga2m.git 

EXPOSE 8080

ADD resources/egiga2m_conf.js /var/www/html/eGiga2m/egiga2m_conf.js
ADD resources/hdb_conf.php /var/www/html/eGiga2m/lib/service/hdb_conf.php 
ADD resources/supervisord.conf /etc/supervisord.conf

USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf
