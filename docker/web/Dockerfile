FROM base:latest
	
USER root
ENV CATALINA_HOME=/var/lib/tomcat8

RUN apt-get update \
    && apt-get -y install \
    nano \
    tomcat8 \
    && cd /var/lib/tomcat8/webapps \
    && wget https://github.com/tango-controls/tango-webapp/releases/download/0.1/TangoWebapp.war \
    && wget https://bitbucket.org/hzgwpn/mtangorest.server/downloads/mtangorest.server-rc4-2.2.jar

ADD resources/tomcat-users.xml /var/lib/tomcat8/conf 
ADD resources/TangoRestServer /var/lib/tomcat8/webapps 
ADD resources/tomcat8 /etc/default/
ADD resources/supervisord.conf /etc/supervisord.conf
ADD resources/tango_register_device /usr/local/bin/

EXPOSE 8080
USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf

