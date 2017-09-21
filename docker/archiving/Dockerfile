FROM tangobox-base:latest


ENV ARCHIVING_ROOT /tmp/mambo
ENV MYSQL_ROOT_PASSWORD secret

COPY resources/initdb.sh /usr/local/bin/
COPY resources/tango_register_device /usr/local/bin/
COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/sample-tdb-device-installation.sql /tmp/mambo/doc/
COPY resources/sample-tdb-device-installation.sql /tmp/mambo/doc/

#mandatory tools
RUN apt-get update && apt-get install -y \
	unzip \
	supervisor \
# install mariadb and mysql
	mariadb-client mariadb-server libmysqlclient-dev libmariadb-client-lgpl-dev

# getting HDB and TDB
RUN wget https://sourceforge.net/projects/tango-cs/files/tools/ArchivingRoot-16.2.4.zip -P/tmp/mambo \
 && cd /tmp/mambo && unzip ArchivingRoot-16.2.4.zip


CMD /usr/bin/supervisord -c /etc/supervisord.conf

