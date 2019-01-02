#!/usr/bin/env bash
# specify version
TANGO_VERSION = 9.3.2
TANGO_RLEASE = 9.3.2-alpha.1

# install dependencies
sudo apt-get install -y build-essential cmake autoconf libtool ant omniidl libomniorb4-dev libcos4-dev libomnithread4-dev libzmq3-dev
sudo apt-get install openjdk-8-jre
java -version
sudo update-alternatives --config java
java -version
sudo apt install libmariadb-dev libmariadbclient-dev

# set environment
sudo cp ../vm/etc/profile /etc/
sudo cp ../vm/etc/tangorc /etc/

# get, build and install tango from source distribution
cd /home/tango-cs/work/tangobox/build
rm -r tango-$TANGO_VERSION
wget https://github.com/tango-controls/TangoSourceDistribution/releases/download/$TANGO_RELEASE/tango-$TANGO_RELEASE.tar.gz
tar -zxf tango-$TANGO_RELEASE.tar.gz

cd tango-$TANGO_VERSION
sudo ./configure --prefix=/usr/local --without-zlib --enable-mariadb --with-mysql-admin=root --with-mariadbclient-include="/usr/include/mysql" --with-mariadbclient-lib="/usr/lib/x86_64-linux-gnu" --enable-dbcreate --enable-dbserver=yes
sudo make
sudo make install
sudo ldconfig

# update priviledges for database
sudo mysql -u root -e "create user tango identified by 'tango';"
sudo mysql -u root -e "grant all on tango.* to 'tango';"

cd /home/tango-cs/work/tangobox/db
sudo mysql -u root < tango-2018-12-18-base.sql

./install-services.sh

. /etc/tangorc
expor TANGO_HOST
