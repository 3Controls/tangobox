#/!/usr/bin/python
#
# client example: reading an attribute , example with spectrum
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys

devname = 'sys/tg_test/1'
attname = 'float_spectrum_ro'

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

print '%s/%s   value[0]: %f ' % (devname,attname,value[0])

# very simple handling of Spectrum (or vector...)
for i in range( 1,value.size):
    print i,value[i]
sys.exit(0)
