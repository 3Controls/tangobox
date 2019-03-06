#!/usr/bin/env bash

# This script installs documentation

mkdir ~/work/documentation
cd ~/work/documentation

# environment
sudo apt-get install python3-venv
python3 -m venv doc-env
source doc-env/bin/activate
pip install sphinx
pip install sphinx_rtd_theme
pip install ipython

# get documentation sources
git clone https://github.com/tango-controls/tango-doc.git
cd tango-doc
git fetch origin
git checkout master
git pull

sphinx-build source build

deactivate


cd ~/Desktop/documentation/
# link to locally built documentation
ln -s ~/work/documentation/tango-doc/build "html"
# get the latest PDF build on the desktop
rm tango-controls.pdf
wget https://buildmedia.readthedocs.org/media/pdf/tango-controls/latest/tango-controls.pdf