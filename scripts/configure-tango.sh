#!/usr/bin/env bash

pip install git+https://github.com/S2Innovation/lib-maxiv-dsconfig.git@dump-class-properties --user

json2tango -w -s 1 -d -v ~/work/tangobox/db/archiving.json
json2tango -w -s 1 -d -v ~/work/tangobox/db/linac.json
json2tango -w -s 1 -d -v ~/work/tangobox/db/sr.json
json2tango -w -s 1 -d -v ~/work/tangobox/db/modbus.json
json2tango -w -s 1 -d -v ~/work/tangobox/db/sardana.json
json2tango -w -s 1 -d -v ~/work/tangobox/db/starters.json
