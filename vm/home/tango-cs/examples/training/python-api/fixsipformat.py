#fix format fro SIP devices
from PyTango import *


sip120 = DeviceProxy('rpcbridge/rpc2tangobridge/sip120')
sip400 = DeviceProxy('rpcbridge/rpc2tangobridge/sip400')



sip120attrlist = sip120.get_attribute_list()

for att in sip120attrlist:
    atconf=sip120.get_attribute_config(att)
    atconf.format='%6.2e'
    try:
        sip120.set_attribute_config(atconf)
    except:
        pass
    
sip400attrlist = sip400.get_attribute_list()

for att in sip400attrlist:
    atconf=sip400.get_attribute_config(att)
    atconf.format='%6.2e'
    try:
        sip400.set_attribute_config(atconf)
    except:
        pass