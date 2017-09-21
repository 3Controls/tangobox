USE tango;

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Temporary DataBase (TDB)

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
--  TDBArchiver				     

INSERT INTO device SET
  name		= "archiving/TDB/TDBarchiver.01_01",
  domain	= "archiving",
  family	= "TDB",
  member	= "TDBarchiver.01_01",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "TDBArchiver/01",
  pid		= 0,
  class 	= "TDBArchiver",
  version	= 0,
  started	= NULL,
  stopped	= NULL;

INSERT INTO device SET
  name		= "archiving/TDB/TDBarchiver.01_02",
  domain	= "archiving",
  family	= "TDB",
  member	= "TDBarchiver.01_02",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "TDBArchiver/02",
  pid		= 0,
  class 	= "TDBArchiver",
  version	= 0,
  started	= NULL,
  stopped	= NULL;

--  TDBExtractor
INSERT INTO device SET
  name		= "archiving/TDB/TDBextractor.1",
  domain	= "archiving",
  family	= "TDB",
  member	= "TDBextractor.1",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "TDBExtractor/1",
  pid		= 0,
  class 	= "TDBExtractor",
  version	= 0,
  started	= NULL,
  stopped	= NULL;

--  HDBTDBArchivingWatcher				     
INSERT INTO device SET
  name		= "archiving/TDB/TDBarchivingwatcher.1",
  domain	= "archiving",
  family	= "TDB",
  member	= "TDBarchivingwatcher.1",
  exported	= 0,
  ior		= "tbd@rt",
  host		= "tbd@rt",
  server	= "HDBTDBArchivingWatcher/TDB",
  pid		= 0,
  class 	= "HDBTDBArchivingWatcher",
  version	= 0,
  started	= NULL,
  stopped	= NULL;


-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Class Properties

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
INSERT INTO property_class (class, name, count, value, updated, accessed, comment) VALUES 
	('TDBArchiver', 'CommitCounter', 1, '10', NULL, NULL, NULL),
	('TDBArchiver', 'DbCnxInactivityTimeout', 1, '1800', NULL, NULL, NULL),
	('TDBArchiver', 'DbHost', 1, 'localhost', NULL, NULL, NULL),
	('TDBArchiver', 'DbMaxPoolSize', 1, '10', NULL, NULL, NULL),
	('TDBArchiver', 'DbMinPoolSize', 1, '2', NULL, NULL, NULL),
	('TDBArchiver', 'DbName', 1, 'TDB', NULL, NULL, NULL),
	('TDBArchiver', 'DbONSConf', 1, 'crshcl:6200', NULL, NULL, NULL),
	('TDBArchiver', 'DbSchema', 1, 'TDB', NULL, NULL, NULL),
	('TDBArchiver', 'DbTnsNames', 1, '(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = crshcl)(PORT = 1521)) (CONNECT_DATA = (SERVICE_NAME = HCL)))', NULL, NULL, NULL),
	('TDBArchiver', 'Facility', 1, 'false', NULL, NULL, NULL),
	('TDBArchiver', 'isDegradMode', 1, 'false', NULL, NULL, NULL),
	('TDBArchiver', 'isRac', 1, 'false', NULL, NULL, NULL);


-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

--                            Devices Properties

-- >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES
	('archiving/TDB/TDBextractor.1', 'DbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),
	('archiving/TDB/TDBextractor.1', 'DbPassword', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL);

INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES 	
	('archiving/TDB/TDBarchiver.01_01', 'DbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),
	('archiving/TDB/TDBarchiver.01_01', 'DbPassword', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchiver.01_01', 'HasThreadedStartup', 1, 'true', NULL, NULL, NULL),  
	('archiving/TDB/TDBarchiver.01_01', 'hasDiary', 1, 'true', NULL, NULL, NULL),  
	('archiving/TDB/TDBarchiver.01_01', 'diaryLogLevel', 1, 'INFO', NULL, NULL, NULL), 
	('archiving/TDB/TDBarchiver.01_01', 'diaryPath', 1, '/home/archivage/tango/TDBarchiver/diary/01', NULL, NULL, NULL),
	('archiving/TDB/TDBarchiver.01_01', 'isDedicated', 1, 'false', NULL, NULL, NULL),
	('archiving/TDB/TDBarchiver.01_01', 'reservedAttributes', 1, '', NULL, NULL, NULL);


INSERT INTO property_device (device, name, count, value, updated, accessed, comment) VALUES 
	('archiving/TDB/TDBarchivingwatcher.1', 'archiverClass', 1, 'TDBArchiver', NULL, NULL, NULL),
	('archiving/TDB/TDBarchivingwatcher.1', 'checkLastValidDate', 1, 'false', NULL, NULL, NULL),
	('archiving/TDB/TDBarchivingwatcher.1', 'cyclePause', 1, '1200000', NULL, NULL, NULL),
	('archiving/TDB/TDBarchivingwatcher.1', 'dbPwd', 1, 'PutYourDataBasePasswordHere', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'dbUser', 1, 'PutYourDabaseUserHere', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'doArchiverDiagnosis', 1, 'true', NULL, NULL, NULL),
	('archiving/TDB/TDBarchivingwatcher.1', 'doDiagnosis', 1, 'true', NULL, NULL, NULL),  
	('archiving/TDB/TDBarchivingwatcher.1', 'doDiffReport', 1, 'false', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'doRetry', 1, 'true', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'exludeList', 1, ' ', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'GapDuration', 1, '900000', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'notificationContact', 1, ' ', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'notificationThreshold', 1, '340', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'onlyIncludeList', 1, ' ', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'periodicReport', 1, '7 days', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'realCheck', 1, 'true', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'safetyPeriod', 1, '15 minutes', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'textTalkerLanguage', 1, 'en', NULL, NULL, NULL),	
	('archiving/TDB/TDBarchivingwatcher.1', 'unitaryPause', 1, '500', NULL, NULL, NULL);
