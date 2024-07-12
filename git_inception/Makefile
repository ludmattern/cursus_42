# Nom du projet
PROJECT_NAME = my-nginx

# Définir les cibles
.PHONY: all build up down clean re

# Par défaut, construire et démarrer les conteneurs
all: up

# Construire les images Docker
build:
	docker-compose -f srcs/docker-compose.yml build

# Démarrer les conteneurs
up: build
	docker-compose -f srcs/docker-compose.yml up -d

# Arrêter et supprimer les conteneurs, images, volumes, et réseaux
down:
	docker-compose -f srcs/docker-compose.yml down --rmi all --volumes --remove-orphans

# Nettoyer les conteneurs et les images
clean: down
	docker system prune -af --volumes

# Reconstruire et redémarrer les conteneurs
re: clean up
