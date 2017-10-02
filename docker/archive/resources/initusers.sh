#!/bin/bash

echo "Adding users to MariaDB..."
mysql -u root < /usr/local/db/add-users.sql

