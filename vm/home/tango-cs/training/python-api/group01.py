#/!/usr/bin/python
#
# client example: using Group object
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys

devpattern = 'powersupply/device/*'
attname = 'Current'

#step 1: creat ethe group

try:
	grp = Group('GTEST')
	grp.add(devpattern)
	print 'number of devices in group:',grp.get_size()
	if grp.ping():
		print 'all devices in group are alive'
	else:
		print 'some devicese in gropu are not alive' 
except DevFailed, ex:
	Except.print_exception(ex)
	sys.exit(1) #semplicistic error handling
    

# execute a command on the group

try:
	grl = grp.command_inout('Status')
	if grl.has_failed():
		print 'some commands failed'
	for rep in grl:
		if rep.has_failed():
			print rep.dev_name(), 'have failed'
		else:
			status = rep.get_data()
			print rep.dev_name(), 'status=',status
except DevFailed, ex:
	Except.print_exception(ex)
	sys.exit(1) #semplicistic error handling
	
try:
	repl = grp.write_attribute('Current',55.77)
	if repl.has_failed():
		print 
		for rep in repl:
			if rep.has_failed():
				print rep.dev_name(), 'have failed'
				errstack = rep.get_err_stack()
				for ex in errstack:
					print ex.desc
					print ex.origin
					print ex.reason
					print ex.severity		
except DevFailed, ex:
	Except.print_exception(ex)
	sys.exit(1) #semplicistic error handling   
sys.exit(0)
