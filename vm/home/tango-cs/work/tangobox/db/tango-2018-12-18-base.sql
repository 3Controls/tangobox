-- MySQL dump 10.16  Distrib 10.1.34-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: tango
-- ------------------------------------------------------
-- Server version	10.1.34-MariaDB-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `access_address`
--

DROP TABLE IF EXISTS `access_address`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `access_address` (
  `user` varchar(255) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  `netmask` varchar(255) DEFAULT 'FF.FF.FF.FF',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `access_address`
--

LOCK TABLES `access_address` WRITE;
/*!40000 ALTER TABLE `access_address` DISABLE KEYS */;
INSERT INTO `access_address` VALUES ('*','*.*.*.*','FF.FF.FF.FF','2006-08-24 11:12:21','2006-08-24 11:12:21');
/*!40000 ALTER TABLE `access_address` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `access_device`
--

DROP TABLE IF EXISTS `access_device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `access_device` (
  `user` varchar(255) DEFAULT NULL,
  `device` varchar(255) DEFAULT NULL,
  `rights` varchar(255) DEFAULT NULL,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `access_device`
--

LOCK TABLES `access_device` WRITE;
/*!40000 ALTER TABLE `access_device` DISABLE KEYS */;
INSERT INTO `access_device` VALUES ('*','*/*/*','write','2006-08-24 11:12:21','2006-08-24 11:12:21');
/*!40000 ALTER TABLE `access_device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `attribute_alias`
--

DROP TABLE IF EXISTS `attribute_alias`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `attribute_alias` (
  `alias` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `device` varchar(255) NOT NULL DEFAULT '',
  `attribute` varchar(255) NOT NULL DEFAULT '',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_attribute_alias` (`alias`(64),`name`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `attribute_alias`
--

LOCK TABLES `attribute_alias` WRITE;
/*!40000 ALTER TABLE `attribute_alias` DISABLE KEYS */;
/*!40000 ALTER TABLE `attribute_alias` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `attribute_class`
--

DROP TABLE IF EXISTS `attribute_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `attribute_class` (
  `class` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_attribute_class` (`class`(64),`name`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `attribute_class`
--

LOCK TABLES `attribute_class` WRITE;
/*!40000 ALTER TABLE `attribute_class` DISABLE KEYS */;
/*!40000 ALTER TABLE `attribute_class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class_attribute_history_id`
--

DROP TABLE IF EXISTS `class_attribute_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `class_attribute_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class_attribute_history_id`
--

LOCK TABLES `class_attribute_history_id` WRITE;
/*!40000 ALTER TABLE `class_attribute_history_id` DISABLE KEYS */;
INSERT INTO `class_attribute_history_id` VALUES (0);
/*!40000 ALTER TABLE `class_attribute_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class_history_id`
--

DROP TABLE IF EXISTS `class_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `class_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class_history_id`
--

LOCK TABLES `class_history_id` WRITE;
/*!40000 ALTER TABLE `class_history_id` DISABLE KEYS */;
INSERT INTO `class_history_id` VALUES (15);
/*!40000 ALTER TABLE `class_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `class_pipe_history_id`
--

DROP TABLE IF EXISTS `class_pipe_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `class_pipe_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class_pipe_history_id`
--

LOCK TABLES `class_pipe_history_id` WRITE;
/*!40000 ALTER TABLE `class_pipe_history_id` DISABLE KEYS */;
INSERT INTO `class_pipe_history_id` VALUES (0);
/*!40000 ALTER TABLE `class_pipe_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `device`
--

DROP TABLE IF EXISTS `device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `device` (
  `name` varchar(255) NOT NULL DEFAULT 'nada',
  `alias` varchar(255) DEFAULT NULL,
  `domain` varchar(85) NOT NULL DEFAULT 'nada',
  `family` varchar(85) NOT NULL DEFAULT 'nada',
  `member` varchar(85) NOT NULL DEFAULT 'nada',
  `exported` int(11) DEFAULT '0',
  `ior` text,
  `host` varchar(255) NOT NULL DEFAULT 'nada',
  `server` varchar(255) NOT NULL DEFAULT 'nada',
  `pid` int(11) DEFAULT '0',
  `class` varchar(255) NOT NULL DEFAULT 'nada',
  `version` varchar(8) NOT NULL DEFAULT 'nada',
  `started` datetime DEFAULT NULL,
  `stopped` datetime DEFAULT NULL,
  `comment` text,
  KEY `name` (`name`(64),`alias`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `device`
--

LOCK TABLES `device` WRITE;
/*!40000 ALTER TABLE `device` DISABLE KEYS */;
INSERT INTO `device` VALUES ('sys/database/2',NULL,'sys','database','2',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000a0000000010102000a00000031302e302e322e31350010270800000064617461626173650300000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000254544140000000010000000900000074616e676f626f7800000000280000002f746d702f6f6d6e692d74616e676f2d63732f3030303030313635372d3135343531323734363700','tangobox','DataBaseds/2',1657,'DataBase','5','2018-12-18 11:04:29','2018-12-10 14:19:13','nada'),('dserver/DataBaseds/2',NULL,'dserver','DataBaseds','2',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000ac000000010102000a00000031302e302e322e313500102714000000647365727665722f646174616261736564732f320300000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000254544140000000010000000900000074616e676f626f7800000000280000002f746d702f6f6d6e692d74616e676f2d63732f3030303030313635372d3135343531323734363700','tangobox','DataBaseds/2',1657,'DServer','5','2018-12-18 11:04:29','2018-12-10 14:19:13','nada'),('sys/rest/0',NULL,'sys','rest','0',1,'IOR:000000000000001749444C3A54616E676F2F4465766963655F353A312E300000000000010000000000000098000102000000000A31302E302E322E313500A91D0000001D3335333332303732352F011A360C4B463C38100630463814141B484C1B000000000000030000000300000016000000000000000B3137322E31372E302E310000A91D00000000000000000008000000004A4143000000000100000024000000000501000100000002000100010001000F00010109000000020501000100010100','tangobox','TangoRestServer/rest',15048,'TangoRestServer','5','2018-12-18 11:29:00',NULL,'nada'),('dserver/TangoRestServer/rest',NULL,'dserver','TangoRestServer','rest',1,'IOR:000000000000001749444C3A54616E676F2F4465766963655F353A312E300000000000010000000000000098000102000000000A31302E302E322E313500A91D0000001D3335333332303732352F001A360C4B463C38100630463814141B484C1B000000000000030000000300000016000000000000000B3137322E31372E302E310000A91D00000000000000000008000000004A4143000000000100000024000000000501000100000002000100010001000F00010109000000020501000100010100','tangobox','TangoRestServer/rest',15048,'DServer','5','2018-12-18 11:29:00','2018-12-18 11:28:57','nada'),('sys/tg_test/1',NULL,'sys','tg_test','1',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350035c70e000000feddcb185c00003a82000000000000000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000035c70000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303031343937382d3135343531323839323500','tangobox','TangoTest/test',14978,'TangoTest','5','2018-12-18 11:28:45',NULL,'nada'),('dserver/TangoTest/test',NULL,'dserver','TangoTest','test',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350035c70e000000feddcb185c00003a82000000000100000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000035c70000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303031343937382d3135343531323839323500','tangobox','TangoTest/test',14978,'DServer','5','2018-12-18 11:28:45','2018-12-18 11:28:45','nada'),('sys/access_control/1',NULL,'sys','access_control','1',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350077c60e000000fe36c6185c00000baa000000000000000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000077c60000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303030323938362d3135343531323734373800','tangobox','TangoAccessControl/1',2986,'TangoAccessControl','5','2018-12-18 11:04:39','2018-12-10 14:19:13','nada'),('dserver/TangoAccessControl/1',NULL,'dserver','TangoAccessControl','1',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350077c60e000000fe36c6185c00000baa000000000100000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000077c60000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303030323938362d3135343531323734373800','tangobox','TangoAccessControl/1',2986,'DServer','5','2018-12-18 11:04:39','2018-12-10 14:19:13','nada'),('tango/admin/tangobox',NULL,'tango','admin','tangobox',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350063b60e000000feafcb185c000039d4000000000000000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000063b60000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303031343830342d3135343531323838373900','tangobox','Starter/tangobox',14804,'Starter','5','2018-12-18 11:28:04',NULL,NULL),('dserver/Starter/tangobox',NULL,'dserver','Starter','tangobox',1,'IOR:010000001700000049444c3a54616e676f2f4465766963655f353a312e3000000100000000000000c4000000010102000a00000031302e302e322e31350063b60e000000feafcb185c000039d4000000000100000400000000000000080000000100000000545441010000001c000000010000000100010001000000010001050901010001000000090101000300000016000000010000000b0000003137322e31372e302e31000063b60000025454413c000000010000000900000074616e676f626f7800000000240000002f746d702f6f6d6e692d726f6f742f3030303031343830342d3135343531323838373900','tangobox','Starter/tangobox',14804,'DServer','5','2018-12-18 11:28:04',NULL,NULL);
/*!40000 ALTER TABLE `device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `device_attribute_history_id`
--

DROP TABLE IF EXISTS `device_attribute_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `device_attribute_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `device_attribute_history_id`
--

LOCK TABLES `device_attribute_history_id` WRITE;
/*!40000 ALTER TABLE `device_attribute_history_id` DISABLE KEYS */;
INSERT INTO `device_attribute_history_id` VALUES (0);
/*!40000 ALTER TABLE `device_attribute_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `device_history_id`
--

DROP TABLE IF EXISTS `device_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `device_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `device_history_id`
--

LOCK TABLES `device_history_id` WRITE;
/*!40000 ALTER TABLE `device_history_id` DISABLE KEYS */;
INSERT INTO `device_history_id` VALUES (11);
/*!40000 ALTER TABLE `device_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `device_pipe_history_id`
--

DROP TABLE IF EXISTS `device_pipe_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `device_pipe_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `device_pipe_history_id`
--

LOCK TABLES `device_pipe_history_id` WRITE;
/*!40000 ALTER TABLE `device_pipe_history_id` DISABLE KEYS */;
INSERT INTO `device_pipe_history_id` VALUES (0);
/*!40000 ALTER TABLE `device_pipe_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `event`
--

DROP TABLE IF EXISTS `event`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `event` (
  `name` varchar(255) DEFAULT NULL,
  `exported` int(11) DEFAULT NULL,
  `ior` text,
  `host` varchar(255) DEFAULT NULL,
  `server` varchar(255) DEFAULT NULL,
  `pid` int(11) DEFAULT NULL,
  `version` varchar(8) DEFAULT NULL,
  `started` datetime DEFAULT NULL,
  `stopped` datetime DEFAULT NULL,
  KEY `index_name` (`name`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `event`
--

LOCK TABLES `event` WRITE;
/*!40000 ALTER TABLE `event` DISABLE KEYS */;
/*!40000 ALTER TABLE `event` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `object_history_id`
--

DROP TABLE IF EXISTS `object_history_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `object_history_id` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `object_history_id`
--

LOCK TABLES `object_history_id` WRITE;
/*!40000 ALTER TABLE `object_history_id` DISABLE KEYS */;
INSERT INTO `object_history_id` VALUES (0);
/*!40000 ALTER TABLE `object_history_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property`
--

DROP TABLE IF EXISTS `property`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property` (
  `object` varchar(255) DEFAULT NULL,
  `name` varchar(255) DEFAULT NULL,
  `count` int(11) DEFAULT NULL,
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_name` (`object`(64),`name`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property`
--

LOCK TABLES `property` WRITE;
/*!40000 ALTER TABLE `property` DISABLE KEYS */;
/*!40000 ALTER TABLE `property` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_attribute_class`
--

DROP TABLE IF EXISTS `property_attribute_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_attribute_class` (
  `class` varchar(255) NOT NULL DEFAULT '',
  `attribute` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_property_attribute_class` (`class`(64),`attribute`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_attribute_class`
--

LOCK TABLES `property_attribute_class` WRITE;
/*!40000 ALTER TABLE `property_attribute_class` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_attribute_class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_attribute_class_hist`
--

DROP TABLE IF EXISTS `property_attribute_class_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_attribute_class_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `class` varchar(255) NOT NULL DEFAULT '',
  `attribute` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_class` (`class`(250)),
  KEY `index_attribute` (`attribute`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_attribute_class_hist`
--

LOCK TABLES `property_attribute_class_hist` WRITE;
/*!40000 ALTER TABLE `property_attribute_class_hist` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_attribute_class_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_attribute_device`
--

DROP TABLE IF EXISTS `property_attribute_device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_attribute_device` (
  `device` varchar(255) NOT NULL DEFAULT '',
  `attribute` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_property_attribute_device` (`device`(64),`attribute`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_attribute_device`
--

LOCK TABLES `property_attribute_device` WRITE;
/*!40000 ALTER TABLE `property_attribute_device` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_attribute_device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_attribute_device_hist`
--

DROP TABLE IF EXISTS `property_attribute_device_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_attribute_device_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `device` varchar(255) NOT NULL DEFAULT '',
  `attribute` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_device` (`device`(250)),
  KEY `index_attribute` (`attribute`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_attribute_device_hist`
--

LOCK TABLES `property_attribute_device_hist` WRITE;
/*!40000 ALTER TABLE `property_attribute_device_hist` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_attribute_device_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_class`
--

DROP TABLE IF EXISTS `property_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_class` (
  `class` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_property` (`class`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_class`
--

LOCK TABLES `property_class` WRITE;
/*!40000 ALTER TABLE `property_class` DISABLE KEYS */;
INSERT INTO `property_class` VALUES ('Database','AllowedAccessCmd',1,'DbGetServerInfo','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',2,'DbGetServerNameList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',3,'DbGetInstanceNameList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',4,'DbGetDeviceServerClassList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',5,'DbGetDeviceList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',6,'DbGetDeviceDomainList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',7,'DbGetDeviceFamilyList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',8,'DbGetDeviceMemberList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',9,'DbGetClassList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',10,'DbGetDeviceAliasList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',11,'DbGetObjectList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',12,'DbGetPropertyList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',13,'DbGetProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',14,'DbGetClassPropertyList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',15,'DbGetClassProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',16,'DbGetDevicePropertyList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',17,'DbGetDeviceProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',18,'DbGetClassAttributeList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',19,'DbGetDeviceAttributeProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',20,'DbGetDeviceAttributeProperty2','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',21,'DbGetLoggingLevel','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',22,'DbGetAliasDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',23,'DbGetClassForDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',24,'DbGetClassInheritanceForDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',25,'DbGetDataForServerCache','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',26,'DbInfo','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',27,'DbGetClassAttributeProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',28,'DbGetClassAttributeProperty2','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',29,'DbMysqlSelect','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',30,'DbGetDeviceInfo','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',31,'DbGetDeviceWideList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',32,'DbImportEvent','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',33,'DbGetDeviceAlias','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',34,'DbGetCSDbServerList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',35,'DbGetDeviceClassList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',36,'DbGetDeviceExportedList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',37,'DbGetHostServerList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',38,'DbGetAttributeAlias2','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',39,'DbGetAliasAttribute','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',40,'DbGetClassPipeProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',41,'DbGetDevicePipeProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',42,'DbGetClassPipeList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',43,'DbGetDevicePipeList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',44,'DbGetAttributeAliasList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Database','AllowedAccessCmd',45,'DbGetForwardedAttributeListForDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',1,'QueryClass','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',2,'QueryDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',3,'EventSubscriptionChange','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',4,'DevPollStatus','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',5,'GetLoggingLevel','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',6,'GetLoggingTarget','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',7,'QueryWizardDevProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',8,'QueryWizardClassProperty','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',9,'QuerySubDevice','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('DServer','AllowedAccessCmd',10,'ZMQEventSubscriptionChange','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Starter','AllowedAccessCmd',1,'DevReadLog','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Starter','AllowedAccessCmd',2,'DevStart','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Starter','AllowedAccessCmd',3,'DevGetRunningServers','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Starter','AllowedAccessCmd',4,'DevGetStopServers','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('Starter','AllowedAccessCmd',5,'UpdateServersInfo','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',1,'GetUsers','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',2,'GetAddressByUser','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',3,'GetDeviceByUser','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',4,'GetAccess','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',5,'GetAllowedCommands','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','AllowedAccessCmd',6,'GetAllowedCommandClassList','2018-12-10 12:16:20','2018-12-10 12:16:20',NULL),('TangoAccessControl','ProjectTitle',1,'Tango Access Control Management','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','Description',5,'It implements also commands used by client API to check access for specified user, device and address.<Br>','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','Description',4,'It implements commands for tool to defines access for users, devices and IP addresses.<Br>','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','Description',2,'<Br>','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','Description',3,'This class defines how to manage the TANGO access control.<Br>','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','Description',1,'This class is a conceate class inherited from AccessControl abstract class.<Br>','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('TangoAccessControl','doc_url',1,'http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/','2018-12-18 10:04:39','2018-12-18 10:04:39',NULL),('TangoAccessControl','InheritedFrom',1,'Tango::Device_4Impl','2018-12-18 10:04:39','2018-12-18 10:04:39',NULL),('TangoAccessControl','Description',6,'And it implements register and unregister it as TANGO service.','2018-12-18 10:04:38','2018-12-18 10:04:38',NULL),('Starter','ProjectTitle',1,'Starter for Tango Administration','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('Starter','Description',1,'This device server is able to control <b>Tango</b> components (database, device servers, clients...).','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('Starter','Description',2,'It is able to start or stop and to report the status of these components.','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('Starter','InheritedFrom',1,'TANGO_BASE_CLASS','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('TangoTest','ProjectTitle',1,'TANGO Device Server for testing generic clients','2018-12-18 10:28:45','2018-12-18 10:28:45',NULL),('TangoTest','Description',1,'A device to test generic clients. It offers a \"echo\" like command for','2018-12-18 10:28:45','2018-12-18 10:28:45',NULL),('TangoTest','Description',2,'each TANGO data type (i.e. each command returns an exact copy of <argin>).','2018-12-18 10:28:45','2018-12-18 10:28:45',NULL),('TangoTest','doc_url',1,'http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/','2018-12-18 10:28:45','2018-12-18 10:28:45',NULL),('TangoTest','InheritedFrom',1,'TANGO_BASE_CLASS','2018-12-18 10:28:45','2018-12-18 10:28:45',NULL);
/*!40000 ALTER TABLE `property_class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_class_hist`
--

DROP TABLE IF EXISTS `property_class_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_class_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `class` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_class` (`class`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_class_hist`
--

LOCK TABLES `property_class_hist` WRITE;
/*!40000 ALTER TABLE `property_class_hist` DISABLE KEYS */;
INSERT INTO `property_class_hist` VALUES (1,'2018-12-10 13:09:00','TangoAccessControl','ProjectTitle',1,'Tango Access Control Management'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',1,'This class is a conceate class inherited from AccessControl abstract class.<Br>'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',2,'<Br>'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',3,'This class defines how to manage the TANGO access control.<Br>'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',4,'It implements commands for tool to defines access for users, devices and IP addresses.<Br>'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',5,'It implements also commands used by client API to check access for specified user, device and address.<Br>'),(2,'2018-12-10 13:09:00','TangoAccessControl','Description',6,'And it implements register and unregister it as TANGO service.'),(3,'2018-12-10 13:09:00','TangoAccessControl','doc_url',1,'http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/'),(4,'2018-12-10 13:09:00','TangoAccessControl','InheritedFrom',1,'Tango::Device_4Impl'),(5,'2018-12-18 10:04:38','TangoAccessControl','ProjectTitle',1,'Tango Access Control Management'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',1,'This class is a conceate class inherited from AccessControl abstract class.<Br>'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',2,'<Br>'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',3,'This class defines how to manage the TANGO access control.<Br>'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',4,'It implements commands for tool to defines access for users, devices and IP addresses.<Br>'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',5,'It implements also commands used by client API to check access for specified user, device and address.<Br>'),(6,'2018-12-18 10:04:38','TangoAccessControl','Description',6,'And it implements register and unregister it as TANGO service.'),(7,'2018-12-18 10:04:39','TangoAccessControl','doc_url',1,'http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/'),(8,'2018-12-18 10:04:39','TangoAccessControl','InheritedFrom',1,'Tango::Device_4Impl'),(9,'2018-12-18 10:27:59','Starter','ProjectTitle',1,'Starter for Tango Administration'),(10,'2018-12-18 10:27:59','Starter','Description',1,'This device server is able to control <b>Tango</b> components (database, device servers, clients...).'),(10,'2018-12-18 10:27:59','Starter','Description',2,'It is able to start or stop and to report the status of these components.'),(11,'2018-12-18 10:27:59','Starter','InheritedFrom',1,'TANGO_BASE_CLASS'),(12,'2018-12-18 10:28:45','TangoTest','ProjectTitle',1,'TANGO Device Server for testing generic clients'),(13,'2018-12-18 10:28:45','TangoTest','Description',1,'A device to test generic clients. It offers a \"echo\" like command for'),(13,'2018-12-18 10:28:45','TangoTest','Description',2,'each TANGO data type (i.e. each command returns an exact copy of <argin>).'),(14,'2018-12-18 10:28:45','TangoTest','doc_url',1,'http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/'),(15,'2018-12-18 10:28:45','TangoTest','InheritedFrom',1,'TANGO_BASE_CLASS');
/*!40000 ALTER TABLE `property_class_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_device`
--

DROP TABLE IF EXISTS `property_device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_device` (
  `device` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `domain` varchar(255) NOT NULL DEFAULT '',
  `family` varchar(255) NOT NULL DEFAULT '',
  `member` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_resource` (`device`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_device`
--

LOCK TABLES `property_device` WRITE;
/*!40000 ALTER TABLE `property_device` DISABLE KEYS */;
INSERT INTO `property_device` VALUES ('tango/admin/tangobox','StartDsPath','','','',1,'/usr/local/bin','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','StartDsPath','','','',2,'/home/tango-cs/bin','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','logging_level','','','',1,'WARNING','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','logging_target','','','',1,'file::/tmp/ds.log/starter_tangobox.log','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','logging_rft','','','',1,'500','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','polled_attr','','','',5,'stoppedservers','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',4,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',3,'runningservers','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',2,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',1,'hoststate','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','UseEvents','','','',1,'0','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','HostUsage','','','',1,'TangoBox common services','2018-12-18 10:27:51','2018-12-18 10:27:51',NULL),('tango/admin/tangobox','polled_attr','','','',6,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',7,'notifdstate','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',8,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',9,'servers','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',10,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',11,'state','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('tango/admin/tangobox','polled_attr','','','',12,'1000','2018-12-18 10:27:59','2018-12-18 10:27:59',NULL),('dserver/Starter/tangobox','polling_threads_pool_conf','','','',1,'tango/admin/tangobox','2018-12-18 10:28:04','2018-12-18 10:28:04',NULL),('dserver/Starter/tangobox','__SubDevices','','','',1,'dserver/tangotest/test','2018-12-18 10:57:59','2018-12-18 10:57:59',NULL),('tango/admin/tangobox','__SubDevices','','','',1,'sys/database/2','2018-12-18 10:57:59','2018-12-18 10:57:59',NULL);
/*!40000 ALTER TABLE `property_device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_device_hist`
--

DROP TABLE IF EXISTS `property_device_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_device_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `device` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_device` (`device`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_device_hist`
--

LOCK TABLES `property_device_hist` WRITE;
/*!40000 ALTER TABLE `property_device_hist` DISABLE KEYS */;
INSERT INTO `property_device_hist` VALUES (1,'2018-12-18 10:27:51','tango/admin/tangobox','StartDsPath',1,'/usr/local/bin'),(1,'2018-12-18 10:27:51','tango/admin/tangobox','StartDsPath',2,'/home/tango-cs/bin'),(2,'2018-12-18 10:27:51','tango/admin/tangobox','logging_level',1,'WARNING'),(3,'2018-12-18 10:27:51','tango/admin/tangobox','logging_target',1,'file::/tmp/ds.log/starter_tangobox.log'),(4,'2018-12-18 10:27:51','tango/admin/tangobox','logging_rft',1,'500'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',1,'hoststate'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',2,'1000'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',3,'runningservers'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',4,'1000'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',5,'stoppedservers'),(5,'2018-12-18 10:27:51','tango/admin/tangobox','polled_attr',6,'1000'),(6,'2018-12-18 10:27:51','tango/admin/tangobox','UseEvents',1,'0'),(7,'2018-12-18 10:27:51','tango/admin/tangobox','HostUsage',1,'TangoBox common services'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',1,'hoststate'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',2,'1000'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',3,'runningservers'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',4,'1000'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',5,'stoppedservers'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',6,'1000'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',7,'notifdstate'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',8,'1000'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',9,'servers'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',10,'1000'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',11,'state'),(8,'2018-12-18 10:27:59','tango/admin/tangobox','polled_attr',12,'1000'),(9,'2018-12-18 10:28:04','dserver/Starter/tangobox','polling_threads_pool_conf',1,'tango/admin/tangobox'),(10,'2018-12-18 10:57:59','dserver/Starter/tangobox','__SubDevices',1,'dserver/tangotest/test'),(11,'2018-12-18 10:57:59','tango/admin/tangobox','__SubDevices',1,'sys/database/2');
/*!40000 ALTER TABLE `property_device_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_hist`
--

DROP TABLE IF EXISTS `property_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `object` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_object` (`object`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_hist`
--

LOCK TABLES `property_hist` WRITE;
/*!40000 ALTER TABLE `property_hist` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_pipe_class`
--

DROP TABLE IF EXISTS `property_pipe_class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_pipe_class` (
  `class` varchar(255) NOT NULL DEFAULT '',
  `pipe` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_property_pipe_class` (`class`(64),`pipe`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_pipe_class`
--

LOCK TABLES `property_pipe_class` WRITE;
/*!40000 ALTER TABLE `property_pipe_class` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_pipe_class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_pipe_class_hist`
--

DROP TABLE IF EXISTS `property_pipe_class_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_pipe_class_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `class` varchar(255) NOT NULL DEFAULT '',
  `pipe` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_class` (`class`(250)),
  KEY `index_pipe` (`pipe`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_pipe_class_hist`
--

LOCK TABLES `property_pipe_class_hist` WRITE;
/*!40000 ALTER TABLE `property_pipe_class_hist` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_pipe_class_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_pipe_device`
--

DROP TABLE IF EXISTS `property_pipe_device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_pipe_device` (
  `device` varchar(255) NOT NULL DEFAULT '',
  `pipe` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  `updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `accessed` timestamp NOT NULL DEFAULT '1999-12-31 23:00:00',
  `comment` text,
  KEY `index_property_pipe_device` (`device`(64),`pipe`(64),`name`(64),`count`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_pipe_device`
--

LOCK TABLES `property_pipe_device` WRITE;
/*!40000 ALTER TABLE `property_pipe_device` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_pipe_device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `property_pipe_device_hist`
--

DROP TABLE IF EXISTS `property_pipe_device_hist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `property_pipe_device_hist` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `device` varchar(255) NOT NULL DEFAULT '',
  `pipe` varchar(255) NOT NULL DEFAULT '',
  `name` varchar(255) NOT NULL DEFAULT '',
  `count` int(11) NOT NULL DEFAULT '0',
  `value` text,
  KEY `index_id` (`id`),
  KEY `index_device` (`device`(250)),
  KEY `index_pipe` (`pipe`(250)),
  KEY `index_name` (`name`(250))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `property_pipe_device_hist`
--

LOCK TABLES `property_pipe_device_hist` WRITE;
/*!40000 ALTER TABLE `property_pipe_device_hist` DISABLE KEYS */;
/*!40000 ALTER TABLE `property_pipe_device_hist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `server`
--

DROP TABLE IF EXISTS `server`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `server` (
  `name` varchar(255) NOT NULL DEFAULT '',
  `host` varchar(255) NOT NULL DEFAULT '',
  `mode` int(11) DEFAULT '0',
  `level` int(11) DEFAULT '0',
  KEY `index_name` (`name`(64))
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `server`
--

LOCK TABLES `server` WRITE;
/*!40000 ALTER TABLE `server` DISABLE KEYS */;
INSERT INTO `server` VALUES ('tangoaccesscontrol/1','tangobox',0,0),('tangotest/test','tangobox',1,2),('tangorestserver/rest','tangobox',1,5);
/*!40000 ALTER TABLE `server` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-12-18 16:17:06
