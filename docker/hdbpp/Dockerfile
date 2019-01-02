FROM debian:stretch-slim

ENV DEBIAN_FRONTEND noninteractive
ENV TANGO_HOST tangobox:10000
ENV MYSQL_ROOT_PASSWORD secret

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/initdb.sh /usr/local/bin/

RUN apt-get update && apt-get install -y \
# mandatory tools/packages
	build-essential \
	sudo \
	apt-transport-https \
	supervisor \
# install mariadb and mysql
	mariadb-client mariadb-server default-libmysqlclient-dev libmariadb-client-lgpl-dev \
 && echo "deb [trusted=yes] https://dl.bintray.com/tango-controls/debian stretch main" | sudo tee -a /etc/apt/sources.list \
 && apt-get update && apt-get install -y \
	hdb++mysql \
	tango-common \
	tango-starter \
	libtango-dev \
	libtango-tools \
 && chmod 755 /usr/lib/tango/Starter \
# cleaning
 && apt-get remove -y && apt-get -y clean \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY resources/add_tables.sh /usr/local/bin/
COPY resources/create_hdb++.sql /usr/share/libhdb++mysql/
COPY resources/my.cnf /etc/mysql/	 

CMD /usr/bin/supervisord -c /etc/supervisord.conf

