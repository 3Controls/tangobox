#!/bin/bash

echo "Adding databases to MariaDB"
echo "Adding ALARMDB..."

mysql -u root < /tmp/mambo/db/create_ALARMDB-Mysql.sql

echo "Adding HDB..."

mysql -u root < /tmp/mambo/db/create-HDB-MyISAM.sql

echo "Adding SNAPDB..."

mysql -u root < /tmp/mambo/db/create-SNAPDB-InnoDB.sql

echo "Adding TDB..."

mysql -u root < /tmp/mambo/db/create-TDB-MyISAM.sql

