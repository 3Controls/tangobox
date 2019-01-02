FROM base:latest

# ENVs
ENV ARCHIVING_ROOT /usr/local
ENV MYSQL_ROOT_PASSWORD secret

# COPY-ies
COPY resources/initdb.sh /usr/local/bin/
COPY resources/tango_register_device /usr/local/bin/
COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/my.cnf /etc/mysql/
COPY resources/initusers.sh /usr/local/bin/
COPY resources/add-users.sql /usr/local/db/

USER root
#mandatory tools
RUN apt-get update && apt-get install -y \
	unzip \
	wget \
# install mariadb and mysql
	mariadb-client mariadb-server libmysqlclient-dev libmariadb-client-lgpl-dev \

# getting HDB, TDB, and SNAP
 && wget https://sourceforge.net/projects/tango-cs/files/tools/ArchivingRoot-16.2.4.zip -P /tmp/mambo \
 && cd /tmp/mambo && unzip ArchivingRoot-16.2.4.zip \
 && cp /tmp/mambo/bin/linux/* /usr/local/bin/ \
 && mkdir /usr/local/conf && cp /tmp/mambo/conf/*.xml /usr/local/conf/ \
 && cp /tmp/mambo/conf/linux/* /usr/local/conf/ \
 && mkdir /usr/local/conf/snap/ && cp /tmp/mambo/conf/snap/* /usr/local/conf/snap/ \
 && cp /tmp/mambo/db/* /usr/local/db/ \
 && cp /tmp/mambo/device/linux/* /usr/local/bin/ \
 && mkdir /usr/local/lib/java/ && cp /tmp/mambo/lib/java/* /usr/local/lib/java/ \
# cleaning
 && apt-get clean -y \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# making executables executable
RUN chmod +x /usr/local/bin/*

# database preparation
RUN bash -c "mysqld_safe --defaults-file=/etc/mysql/my.cnf &"\
 && sleep 5 \
 && /usr/local/bin/initdb.sh \
 && /usr/local/bin/initusers.sh \
 && sleep 10

USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf
