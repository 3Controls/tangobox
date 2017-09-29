FROM base:latest

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/
USER root
RUN pip install sardana
USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf
