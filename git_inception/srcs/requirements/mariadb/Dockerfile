# Utiliser l'image de base Debian 11
FROM debian:11

# Installer les paquets nécessaires
RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Créer les répertoires pour le socket MySQL
RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

# Copier les scripts SQL et bash pour créer la table
COPY init-db.sql /init-db.sql
COPY docker-entrypoint.sh /usr/local/bin/

# Rendre le script exécutable
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

# Exposer le port 3306
EXPOSE 3306

# Définir le script comme point d'entrée
ENTRYPOINT ["docker-entrypoint.sh"]

# Définir la commande par défaut
CMD ["mysqld"]
