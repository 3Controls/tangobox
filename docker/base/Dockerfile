FROM ubuntu:16.04

ENV DEBIAN_FRONTEND noninteractive
ENV TANGO_HOST TangoBox-VM:10000

ADD ../../resources/supervisord.conf /etc/supervisord.conf
ADD ../../resources/tango_register_device /usr/local/bin/
#adding PyAlarm DS
ADD /usr/local/lib/python2.7/dist-packages/panic-6.0.6-py2.7.egg/panic/ds/PyAlarm.py /usr/local/bin/

RUN apt-get update && apt-get install -y \
    # mandatory packages/tools
    build-essential \
    wget \
    bzip2 \
    pkg-config \
    #Python
    -qq python2.7 \
    python-dev \
    python-pip \
    # Tango dependencies
    default-jdk \
    libzmq3-dev \
    libomniorb4-dev libcos4-dev omniidl \
    # Tango-9.2.5a
 && wget https://sourceforge.net/projects/tango-cs/files/tango-9.2.5a.tar.gz -P /tmp && cd /tmp/ && tar xvfz tango-9.2.5a.tar.gz \
 && tango-9.2.5a/configure --prefix=/usr/local --enable-java --enable-mariadb --disable-dbserver \
 && make && make install \
    # PyTango dependencies
 && apt-get install -y \
    libboost-all-dev \
    libboost-dev \
    libboost-python-dev \
 && pip install -U \
    numpy \
    six \
    setuptools \
    #PyTango
    pytango \
# cleaning
 && apt-get -y clean \
 && alias python=python2.7 \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

CMD /bin/bash \
    /usr/bin/supervisord -c /etc/supervisord.conf
