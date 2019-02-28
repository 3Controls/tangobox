FROM base:latest

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/

ENV TANGO_HOST tangobox:10000


#Installing packets for compiling linac  classes
RUN sudo apt-get update \ 
    && sudo apt-get -y install flex \
    && sudo apt-get -y clean \
    && sudo apt-get -y autoclean \
    && sudo apt-get -y autoremove \
    && sudo chown -R tango-cs:tango-cs /home/tango-cs/dservers

USER tango-cs
ADD resources/linac /home/tango-cs/dservers/linac
RUN sudo chown -R tango-cs:tango-cs /home/tango-cs

RUN cd /home/tango-cs/dservers/linac/bin/ \
    && bash make.all \
    && bash linac.copy

#CMD /home/tango-cs/dservers/linac/bin/linac.start
CMD /usr/bin/supervisord -c /etc/supervisord.conf


