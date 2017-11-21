#/!/usr/bin/python
#
# client example: subscribing to an attribute event change
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys
import time

devname = 'sys/tg_test/1'
attname = 'double_scalar'

#step 1) define the callback class
class MyCbClass:
    def __init__(self):
        self.num_calls=0
        pass
    def push_event(self, event_data):
        if event_data.err == False:
            try:
                evtype = event_data.event
                # if evtype == 'change: ## you can handle different type of events 
                da= event_data.attr_value # type is device PyTango.DeviceAttribute
                val = da.value
                w_val = da.w_value
                self.num_calls += 1
                print da.get_date(), val, w_val,self.num_calls,evtype
            except :
                print 'exception while extract event data'
        else:
            print 'event error:',event_data.errors[0].desc, event_data.errors[0].origin ,event_data.errors[0].reason, event_data.errors[0].severity

#step 2) create the device proxy
devname = 'sys/tg_test/1'

try:
    dev = DeviceProxy(devname)
    print 'proxy for %s created' %(devname)
except DevFailed, ex:
        Except.print_exception(ex)
        sys.exit(1) #semplicistic error handling

#step 3) subscribe the event
evid = 0
MyCb = MyCbClass() #creat a callback object
try:
    evid = dev.subscribe_event(attname, EventType.CHANGE_EVENT, MyCb,[],False) # empty filtes, stateless flag, dafault is False
except DevFailed, ex:
        Except.print_exception(ex)
        #sys.exit(1) #semplicistic error handling
time.sleep(100)
if evid > 0 :
    dev.unsubscribe_event(evid)
    print 'event unsubscribed'
sys.exit(0)
