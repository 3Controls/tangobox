#/!/usr/bin/python
#
# client example: browsing the structure, properties, etc of a Tango Device
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys


dev = DeviceProxy('sys/tg_test/1')

# query the the list of attributes

attlist = dev.get_attribute_list()

for att in attlist:
    print att
    
    
#analyze on of the attributes
atconf = dev.get_attribute_config_ex(attlist[0])[0]
print 'name:',atconf.name,' min_alarm=',atconf.alarms.min_alarm

#now set the new the new attribute alarm limits

atconf.alarms.min_alarm='0.1'
atconf.alarms.max_alarm='10.0'
dev.set_attribute_config(atconf)



#notice : value for attributes are always strings!


#you can set the polling period - good for bulk cotrl system configuration

dev.poll_attribute('ampli',3000)

#ore remove poolling
dev.stop_poll_attribute('ampli')

print '----------------------------------'

#query the list of commands
# notice that python method is a little different from C++ get_command_list
# it directly queries command namens and command info - in C++ must do a specific query for each cammmand to get the config.
cmdlist = dev.command_list_query()
for cmd in cmdlist:
    print cmd.cmd_name
    pass


