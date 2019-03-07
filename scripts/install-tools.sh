#!/usr/bin/env bash

# This script installs set of  Tango tools 

# Python tools
sudo apt install python-pip
sudo apt install python-qt4
sudo apt install qt4-designer
sudo apt install python-qwt python-qwt5-qt4 python-guiqwt python-numpy
sudo apt install python-pymca python-pymca5
sudo apt install libboost-python-dev
sudo apt install python-pyqt5.qtwebkit
sudo apt install python-pyqt5.qtsvg
sudo apt install python-spyder
sudo apt install python-spyderlib
sudo apt install python-html5lib 
sudo apt install python-ipython
sudo apt install python-ply

pip install numpy --user
pip install sphinx --user
pip install sphinx_rtd_theme --user
pip install lxml --user
pip install pytango --user
pip install fandango --user
pip install PyTangoArchiving --user
pip install itango --user
pip install taurus --user
pip install panic --user
pip install sardana --user

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
# wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/HDB++.jar
wget -O libhdbpp-java.jar https://bintray.com/tango-controls/maven/download_file?file_path=org%2Ftango%2Flibhdbpp-java%2F1.21%2Flibhdbpp-java-1.21.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/jcalendar.jar
wget http://ftp.esrf.eu/pub/cs/tango/hdbviewer/jython.jar
wget -O jhdbviewer.jar https://bintray.com/tango-controls/maven/download_file?file_path=org%2Ftango%2Fjhdbviewer%2F1.14%2Fjhdbviewer-1.14.jar
cd ../bin
chmod +x *
ln -s -t ~/bin ~/tools/archiving-hdbpp/bin/* 
