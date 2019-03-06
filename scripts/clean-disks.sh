#!/usr/bin/env bash
echo "Before cleaning:"
df -h | grep /dev/sda1
sudo apt-get -y clean
sudo apt-get -y autoclean
sudo apt-get -y autoremove --purge
rm -rf /home/tango-cs/.cache/*
sudo rm -rf /home/tango-cs/work/tangobox/build/*
docker image prune -a

echo "After cleaning:"
df -h | grep /dev/sda1
