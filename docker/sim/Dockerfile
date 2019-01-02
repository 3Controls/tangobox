FROM base:latest

ENV TANGO_HOST tangobox:10000
#adding linac files
ADD linac/ /home/tango-cs/dservers/linac

##Linac configuration
#Installing packets for compiling linac  classes
RUN sudo apt-get update \ 
    && sudo apt-get -y install nano flex \
    && cd /home/tango-cs/dservers/linac/bin/ \
    && sudo bash make.all \
    && sudo bash linac.copy \
#    && sudo bash linac.start

CMD /usr/bin/supervisord -c /etc/supervisord.conf


