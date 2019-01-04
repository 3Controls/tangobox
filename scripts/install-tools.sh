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

