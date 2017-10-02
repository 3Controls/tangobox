USE tango;

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Historical DataBase (HDB)

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
--  HdbArchiver				     

INSERT INTO device SET
  name		= "archiving/hdb/hdbarchiver.01_01",
  domain	= "archiving",
  family	= "hdb",
  member	= "hdbarchiver.01_01",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "HdbArchiver/01",
  pid		= 0,
  class 	= "HdbArchiver",
  version	= 0,
  started	= NULL,
  stopped	= NULL;


INSERT INTO device SET
  name		= "archiving/hdb/hdbarchiver.01_02",
  domain	= "archiving",
  family	= "hdb",
  member	= "hdbarchiver.01_02",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "HdbArchiver/02",
  pid		= 0,
  class 	= "HdbArchiver",
  version	= 0,
  started	= NULL,
  stopped	= NULL;

--  HdbExtractor
INSERT INTO device SET
  name		= "archiving/hdb/hdbextractor.1",
  domain	= "archiving",
  family	= "hdb",
  member	= "hdbextractor.1",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "HdbExtractor/1",
  pid		= 0,
  class 	= "HdbExtractor",
  version	= 0,
  started	= NULL,
  stopped	= NULL;

--  HDBTDBArchivingWatcher				     
INSERT INTO device SET
  name		= "archiving/hdb/hdbarchivingwatcher.1",
  domain	= "archiving",
  family	= "hdb",
  member	= "hdbarchivingwatcher.1",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "HDBTDBArchivingWatcher/HDB",
  pid		= 0,
  class 	= "HDBTDBArchivingWatcher",
  version	= 0,
  started	= NULL,
  stopped	= NULL;


-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Class Properties

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
INSERT INTO property_class (class, name, count, value, updated, accessed, comment) VALUES 
	('HdbArchiver', 'CommitCounter', 1, '10', NULL, NULL, NULL),
	('HdbArchiver', 'DbCnxInactivityTimeout', 1, '1800', NULL, NULL, NULL),
	('HdbArchiver', 'DbHost', 1, 'localhost', NULL, NULL, NULL),
	('HdbArchiver', 'DbMaxPoolSize', 1, '10', NULL, NULL, NULL),
	('HdbArchiver', 'DbMinPoolSize', 1, '2', NULL, NULL, NULL),
	('HdbArchiver', 'DbName', 1, 'hdb', NULL, NULL, NULL),
	('HdbArchiver', 'DbONSConf', 1, 'crshcl:6200', NULL, NULL, NULL),
	('HdbArchiver', 'DbSchema', 1, 'hdb', NULL, NULL, NULL),
	('HdbArchiver', 'DbTnsNames', 1, '(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = crshcl)(PORT = 1521)) (CONNECT_DATA = (SERVICE_NAME = HCL)))', NULL, NULL, NULL),
	('HdbArchiver', 'Facility', 1, 'false', NULL, NULL, NULL),
	('HdbArchiver', 'isDegradMode', 1, 'false', NULL, NULL, NULL),
	('HdbArchiver', 'isRac', 1, 'false', NULL, NULL, NULL);


-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Devices Properties

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES
	('archiving/hdb/hdbextractor.1', 'DbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),
	('archiving/hdb/hdbextractor.1', 'DbPassword', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL);

INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES 	
	('archiving/hdb/hdbarchiver.01_01', 'DbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),
	('archiving/hdb/hdbarchiver.01_01', 'DbPassword', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchiver.01_01', 'HasThreadedStartup', 1, 'true', NULL, NULL, NULL),  
	('archiving/hdb/hdbarchiver.01_01', 'hasDiary', 1, 'true', NULL, NULL, NULL),  
	('archiving/hdb/hdbarchiver.01_01', 'diaryLogLevel', 1, 'INFO', NULL, NULL, NULL), 
	('archiving/hdb/hdbarchiver.01_01', 'diaryPath', 1, '/home/archivage/tango/hdbarchiver/diary/01', NULL, NULL, NULL),
	('archiving/hdb/hdbarchiver.01_01', 'isDedicated', 1, 'false', NULL, NULL, NULL),
	('archiving/hdb/hdbarchiver.01_01', 'reservedAttributes', 1, '', NULL, NULL, NULL);


INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES 
	('archiving/hdb/hdbarchivingwatcher.1', 'archiverClass', 1, 'HdbArchiver', NULL, NULL, NULL),
	('archiving/hdb/hdbarchivingwatcher.1', 'checkLastValidDate', 1, 'false', NULL, NULL, NULL),
	('archiving/hdb/hdbarchivingwatcher.1', 'cyclePause', 1, '1200000', NULL, NULL, NULL),
	('archiving/hdb/hdbarchivingwatcher.1', 'dbPwd', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'dbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'doArchiverDiagnosis', 1, 'true', NULL, NULL, NULL),
	('archiving/hdb/hdbarchivingwatcher.1', 'doDiagnosis', 1, 'true', NULL, NULL, NULL),  
	('archiving/hdb/hdbarchivingwatcher.1', 'doDiffReport', 1, 'false', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'doRetry', 1, 'true', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'exludeList', 1, ' ', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'GapDuration', 1, '900000', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'notificationContact', 1, ' ', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'notificationThreshold', 1, '340', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'onlyIncludeList', 1, ' ', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'periodicReport', 1, '7 days', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'realCheck', 1, 'true', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'safetyPeriod', 1, '15 minutes', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'textTalkerLanguage', 1, 'en', NULL, NULL, NULL),	
	('archiving/hdb/hdbarchivingwatcher.1', 'unitaryPause', 1, '500', NULL, NULL, NULL);
