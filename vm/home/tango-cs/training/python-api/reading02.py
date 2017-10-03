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
    print 'attribute name:' , da.name
    print 'attibute_timestamp:', da.get_date()  # att.date
    print 'attribute_quality:', da.quality
    print 'attribute_dim_x:', da.dim_x
    print 'attribute_type:', da.type
    print 'attribute.value :' ,da.value
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to read attribute'
    sys.exit(1) #simplicistic error handling

    #set a value with jive and check the result here
try:
    da = dev.read_attribute(attname) #read again the attribute
    print 'attribute.value    (reading):' ,da.value
    print 'attribute.w_value  (setting):' ,da.w_value  #simpler than C++
except DevFailed, ex:
    Except.print_exception(ex)
    print 'failed to read attribute'
    sys.exit(1) #simplicistic error handling
sys.exit(0)