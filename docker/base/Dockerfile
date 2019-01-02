FROM ubuntu:16.04

ENV DEBIAN_FRONTEND noninteractive
ENV TANGO_HOST tangobox:10000

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/

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
	supervisor \
    # Tango-9.2.5a
 && wget https://sourceforge.net/projects/tango-cs/files/tango-9.2.5a.tar.gz -P /tmp && cd /tmp/ && tar xvfz tango-9.2.5a.tar.gz \
 && tango-9.2.5a/configure --prefix=/usr/local --enable-java --enable-mariadb --disable-dbserver \
 && make && make install \
    # PyTango dependencies
 && apt-get install -y \
    libboost-all-dev \
    libboost-dev \
    libboost-python-dev \
    sudo \
 && pip install -U \
    numpy \
    six \
    setuptools \
    #PyTango
    pytango \
    fandango \
    panic \ 	
# cleaning
 && apt-get -y clean \
 && alias python=python2.7 \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* \
# adding user 
 && useradd -ms /bin/bash tango-cs \
 && tango-cs:tango | chpasswd \
 && echo "tango-cs ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/tango-cs \
 && chmod 0440 /etc/sudoers.d/tango-cs \
 && mkdir /home/tango-cs/dservers	
USER tango-cs
# supervisor
CMD /usr/bin/supervisord -c /etc/supervisord.conf
