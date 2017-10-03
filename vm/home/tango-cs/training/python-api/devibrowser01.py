#/!/usr/bin/python
#
# client example: readn and browsing the tango Db
# C. Scafuri - jan. 2016
#

from PyTango import *
import sys


import os

print os.environ['TANGO_HOST']
#os.environ['TANGO_HOST']='tom:20000' -- if you need to specify a different Db use this trick

db = Database()

# exploing domain/family/member


#get the full list of domains - use wildcard for query

dmlist = db.get_device_domain('*') #get list of domains

# dml is of typ DbDatum
print 'dm list length:', len(dmlist.value_string)
for dm in dmlist.value_string:
	print dm
	dmquery = dm+'/*'
	famlist=db.get_device_family(dmquery) #get list ff families for each domains
	for fam in famlist.value_string:
		print'\t',fam
		famquery=dm+'/'+fam+'/*'
		print '-------->',famquery
		memlist = db.get_device_member(famquery) #get the list of members for each domain/family
		for mem in memlist:
			print '\t\t',mem




