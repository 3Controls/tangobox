#/!/usr/bin/python
#
# client example: reading an attribute , also with simplified syntax
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys

devname = 'sys/tg_test/1'
attname = 'double_scalar'

#step 1) create the device proxy
try:
    dev = DeviceProxy(devname)
    print 'proxy for %s created' %(devname)
except DevFailed, ex:
        Except.print_exception(ex)
        sys.exit(1) #semplicistic error handling
        
#step 2 read the attribute
try:
    da = dev.read_attribute(attname) #read the attribute
    value=da.value
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to read attribute'
    sys.exit(1) #simplicistic error handling

print '%s/%s   value: %f ' % (devname,attname,value)

#step3 use simplified interface

try:
    value2 = dev.double_scalar
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to read double_scalar'
    sys.exit(1) #simplicistic error handling

    
print '%s/%s  value2: %f ' % (devname,attname,value2)
sys.exit(0)
