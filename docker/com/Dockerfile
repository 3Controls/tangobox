FROM base:latest

COPY resources/ModbusDS /usr/local/bin/
COPY resources/SerialLine /usr/local/bin/
COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/

RUN git clone https://github.com/sergirubio/PyPLC.git \
    && cd PyPLC \
    && sudo python setup.py install
    #check install dir


CMD /usr/bin/supervisord -c /etc/supervisord.conf