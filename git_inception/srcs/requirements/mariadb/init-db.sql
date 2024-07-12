CREATE DATABASE IF NOT EXISTS wordpress;
USE wordpress;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL,
    email VARCHAR(100)
);

# Créer un utilisateur pour WordPress
CREATE USER IF NOT EXISTS 'wp_user'@'%' IDENTIFIED BY 'wp_password';

# Accorder tous les privilèges à lutilisateur WordPress
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp_user'@'%';

# Appliquer les modifications de privilèges
FLUSH PRIVILEGES;