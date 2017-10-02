#!/usr/bin/python
#
# client example: executing asynch commands
# C. Scafuri - jan. 2016
#

from PyTango import *
import time

#step 1) define the callback class
class MyCbClass:
    def __init__(self):
        self.num_calls=0
        pass
    def cmd_ended(self, event_data):
        if event_data.err == False:
            #event_data class is CmdEventDone
            try:
                dev_data = event_data.argout_raw #get the DevicData object
                cmd_result = dev_data.extract()  #extract the value
                self.num_calls += 1
                print event_data.cmd_name, cmd_result, self.num_calls
            except :
                print 'exception while extract event data'
        else:
            print 'event error:',event_data.errors[0].desc, event_data.errors[0].origin ,event_data.errors[0].reason, event_data.errors[0].severity




devname = 'sys/tg_test/1'

try:
    dev = DeviceProxy(devname)
    
except DevFailed, ex:
    print 'failed to create DeviceProxy'
    PyTango.Excpetion.print_exception(ex)
    exit(1)

MyCb = MyCbClass() #creat a callback object   
au = ApiUtil.instance()
au.set_asynch_cb_sub_model(cb_sub_model.PUSH_CALLBACK)
try:
    dev.command_inout_asynch('DevShort',1233,MyCb)

except DevFailed, ex:
    print 'failed to execute command_inout_async DevShort'

count = 0
while count < 10:
    print '-'
    count += 1
    time.sleep(0.01)
