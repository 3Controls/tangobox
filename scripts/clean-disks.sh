#!/usr/bin/env bash

sudo apt-get -y clean
sudo apt-get -y autoclean
sudo apt-get -y autoremove
rm -rf /home/tango-cs/.cache/*
rm -rf /home/tango-cs/work/tangobox/build/*
