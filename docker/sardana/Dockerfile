FROM base:latest

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/
USER root
RUN pip install --upgrade pip \
    && pip install sardana h5py \
    && apt-get update && apt-get install -y gir1.2-gtk-3.0
USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf
