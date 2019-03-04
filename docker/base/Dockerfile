FROM ubuntu:16.04

ENV DEBIAN_FRONTEND noninteractive
ENV TANGO_HOST tangobox:10000

COPY resources/supervisord.conf /etc/supervisord.conf
COPY resources/tango_register_device /usr/local/bin/

RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    bzip2 unzip \
    pkg-config \
    -qq python2.7 \
    mariadb-client libmysqlclient-dev libmariadb-client-lgpl-dev \
    python-dev \
    python-pip \
    python-mysqldb \
    git \ 
    nano \
    default-jdk \
    libzmq3-dev \
    libomniorb4-dev libcos4-dev omniidl \
    supervisor

# Tango-9.2.5a
RUN wget https://sourceforge.net/projects/tango-cs/files/tango-9.2.5a.tar.gz -P /tmp && cd /tmp/ && tar xvfz tango-9.2.5a.tar.gz \
 && tango-9.2.5a/configure --prefix=/usr/local --enable-java --enable-mariadb --disable-dbserver \
 && make && make install

# Prepare for PyTango
RUN apt-get install -y \
    libboost-all-dev \
    libboost-dev \
    libboost-python-dev \
    sudo \
 && alias python='python2.7'

# cleaning
RUN apt-get -y clean \
 && apt-get -y autoclean \
 && apt-get -y autoremove \
 && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# adding a user 
RUN  useradd -ms /bin/bash tango-cs \
 && echo "tango-cs:tango" | chpasswd \
 && echo "tango-cs ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/tango-cs \
 && chmod 0440 /etc/sudoers.d/tango-cs \
 && mkdir /home/tango-cs/dservers

USER tango-cs
# add pytango and tools
RUN alias python='python2.7' \
 && sudo -H python -m pip install --upgrade --no-cache-dir pip \
 && pip install -U --no-cache-dir --user \
    numpy \
    six \
    setuptools \
    pytango \
    fandango \
    PyTangoArchiving \
    panic

RUN rm -rf /home/tango-cs/.cache	


# supervisor
CMD /usr/bin/supervisord -c /etc/supervisord.conf
