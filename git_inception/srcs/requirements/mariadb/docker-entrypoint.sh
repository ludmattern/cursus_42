#!/bin/bash
set -e

# Démarrer MariaDB en arrière-plan
mysqld &

# Attendre que MariaDB soit prêt
until mysqladmin ping >/dev/null 2>&1; do
    echo "Waiting for MariaDB to start..."
    sleep 2
done

# Remplacer les variables d'environnement dans le fichier SQL
sed -i "s/MYSQL_DATABASE/$MYSQL_DATABASE/g" /init-db.sql
sed -i "s/MYSQL_USER/$MYSQL_USER/g" /init-db.sql
sed -i "s/MYSQL_PASSWORD/$MYSQL_PASSWORD/g" /init-db.sql

# Exécuter le script SQL d'initialisation
mysql -u root < /init-db.sql

# Arrêter MariaDB
mysqladmin shutdown

# Modifier la configuration pour écouter sur toutes les interfaces
sed -i 's/bind-address\s*=\s*127.0.0.1/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

# Démarrer MariaDB au premier plan
exec mysqld
