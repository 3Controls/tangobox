#!/usr/bin/env bash
sudo cp -r ../vm/etc/systemd/system/tango* /etc/systemd/system/
sudo systemctl enable tango.target
sudo systemctl start tango.target
