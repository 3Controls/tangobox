FROM base:latest
	
USER root

ENV JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-amd64/jre
ENV CATALINA_PID=/opt/tomcat/temp/tomcat.pid
ENV CATALINA_HOME=/opt/tomcat
ENV CATALINA_BASE=/opt/tomcat

RUN cd /opt \
    && wget http://ftp.man.poznan.pl/apache/tomcat/tomcat-8/v8.5.38/bin/apache-tomcat-8.5.38.tar.gz \
    && sudo mkdir /opt/tomcat \
    && sudo tar xzvf apache-tomcat-8*tar.gz -C /opt/tomcat --strip-components=1 \
    && rm -r apache-tomcat-8.5.38.tar.gz \
    && cd /opt/tomcat \
    && sudo chgrp -R tango-cs /opt/tomcat \
    && sudo chmod -R g+r conf \
    && sudo chmod g+x conf \
    && sudo chown -R tango-cs webapps/ work/ temp/ logs/ 

RUN cd /opt/tomcat/webapps \
    && wget https://github.com/tango-controls/waltz/releases/download/v0.6.1/TangoWebapp.war \
    && sudo chmod 755 TangoWebapp.war

#cleaning
RUN sudo apt-get -y clean \
    && sudo apt-get -y autoclean \
    && sudo apt-get -y autoremove

EXPOSE 8080
ADD resources/web.xml /opt/tomcat/webapps/tango/WEB_INF/web.xml
ADD resources/tomcat-users.xml /opt/tomcat/conf/tomcat-users.xml
ADD resources/tomcat8 /etc/default/tomcat8
ADD resources/supervisord.conf /etc/supervisord.conf
ADD resources/tango_register_device /usr/local/bin/

USER tango-cs

CMD /usr/bin/supervisord -c /etc/supervisord.conf

