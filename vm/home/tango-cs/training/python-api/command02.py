#!/usr/bin/python
#
# client example: executing commands with simplified syntax
# C. Scafuri - jan. 2016
#

from PyTango import *

devname = 'sys/tg_test/1'
cmdname = 'DevShort'

try:
    dev = DeviceProxy(devname)
    
except DevFailed, ex:
    print 'failed to create DeviceProxy'
    PyTango.Excpetion.print_exception(ex)
    exit(1)
    
try:
    dataout = dev.DevShort(1234) ## simplified and more natural syntax
    print 'command_inout DevShort result:', dataout
    
    mydbl = 1.22    #here mydbl  is a float
    mystr = 'ABC'   #here mystr  is a string
    print 'types of variables before dataout extraction:',type( dataout), type(mydbl), type(mystr)
    mydbl = dataout #here mydbl turns into a short
    mystr = dataout #here mystr turns into a short
    print 'command_inout DevoVoid results extratect to existing variable:', dataout, mydbl, mystr, type( dataout), type(mydbl), type(mystr)
    # type of variables changes if handled by python! powerful,  easy , can play tricks...
except DevFailed, ex:
    print 'failed to execute command DevShort'
    
# now with DevVoid
try:
    dev.DevVoid()
    print 'command_inout devVoid OK'

except DevFailed, ex:
    print 'failed to execute command DevVoid'
