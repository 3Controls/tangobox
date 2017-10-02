#!/bin/bash

echo "Adding databases to MariaDB"
echo "Adding ALARMDB..."
mysql -u root < /usr/local/db/create_ALARMDB-Mysql.sql
echo "Adding HDB..."
mysql -u root < /usr/local/db/create-HDB-MyISAM.sql
echo "Adding SNAPDB..."
mysql -u root < /usr/local/db/create-SNAPDB-InnoDB.sql
echo "Adding TDB..."
mysql -u root < /usr/local/db/create-TDB-MyISAM.sql
