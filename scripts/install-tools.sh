#!/usr/bin/env bash

# This script install set of  Tango tools 

# archiving suit from SOLEIL (java)
cd ~/work/tangobox/build/
wget -O ArchivingRoot.zip https://sourceforge.net/projects/tango-cs/files/tools/ArchivingRoot-16.2.4.zip/download
mkdir -p ~/tools/archiving-java
unzip -d ~/tools/archiving-java/ ArchivingRoot.zip
# update start scripts to use bash
cd ~/tools/archiving-java/bin/linux
sed -i 's/\/bin\/sh/\/bin\/bash/' *
# make sure the executables are executable
chmod +x *
# link executables in ~/bin
ln -s ~/tools/archiving-java/bin/linux/* ~/bin/

# HDB++
mkdir -p ~/tools/archiving-hdbpp
cd ~/tools/archiving-hdbpp
mkdir java
cd java
wget -O hdbpp-configurator.jar https://bintray.com/tango-controls/maven/download_file?file_path=org%2Ftango%2Fhdb%2Fhdbpp-configurator%2F3.10%2Fhdbpp-configurator-3.10.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/HDB++.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/jcalendar.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/jython.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/jhdbviewer.jar
cd ../bin
chmod +x *
ln -s -t ~/bin ~/tools/archiving-hdbpp/bin/* 
