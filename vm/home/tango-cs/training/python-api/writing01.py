#/!/usr/bin/python
#
# client example: wrting an attribute , also with simplified syntax
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
try:
    dev.write_attribute(attname,5.678) #write the attribute directly
    print 'write_attribute "%s" OK' % (attname)
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to write attribute'
    sys.exit(1) #simplicistic error handling
    
# use simplified syntax:

try:
    dev.double_scalar=0.619
    print 'write_attribute SIMPLIFIED "%s" OK' % (attname)
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to write attribute with simplified sytax'
    sys.exit(1) #simplicistic error handling

sys.exit(0)
