FROM base:latest

COPY resources/Modbus /usr/local/bin/
COPY resources/ModbusComposer /usr/local/bin/
COPY resources/Serial /usr/local/bin/
COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/

USER root 
RUN apt-get update && apt-get install -y \
    git \
    unzip \
    && git clone https://github.com/sergirubio/PyPLC.git \
    && cd PyPLC \
    && sudo python setup.py install 
#    && cd /usr/local/lib/python2.7/dist-packages \
#    && sudo unzip pyplc-7.7-py2.7.egg

USER tango-cs
CMD /usr/bin/supervisord -c /etc/supervisord.conf
