#/!/usr/bin/python
#
# client example: reading an attribute , also with simplified syntax
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys

devname = 'sys/tg_test/1'
attname = 'double_spectrum'

#step 1) create the device proxy
try:
    dev = DeviceProxy(devname)
    print 'proxy for %s created' %(devname)
except DevFailed, ex:
        Except.print_exception(ex)
        sys.exit(1) #semplicistic error handling
#prepare value list
value = []
for i in range(0,255,1):
    value.append(i/10.0)
try:
    dev.write_attribute(attname,value)
    print 'write_attribute "%s" OK' % (attname)
except DevFailed, ex:
        Except.print_exception(ex)
        sys.exit(1) #semplicistic error handling

#use numpy.ndarray - must import numpy 
import numpy
arrvalue=numpy.empty((255))
for i in range(0,255,1):
    arrvalue[i]= i/20.0

try:
    dev.write_attribute(attname,arrvalue)
    dev.float_spectrum=arrvalue  #use alternative syntax - on another attribute
    print 'write_attribute "%s" with numpy.ndarray OK' % (attname)
except DevFailed, ex:
        Except.print_exception(ex)
        sys.exit(1) #semplicistic error handling


sys.exit(0)