# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmattern <lmattern@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 16:31:02 by lmattern          #+#    #+#              #
#    Updated: 2024/07/13 21:57:08 by lmattern         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Nom du projet
PROJECT_NAME = inception

# Définir les cibles
.PHONY: all build up down clean re

# Par défaut, construire et démarrer les conteneurs
all: up

# Construire les images
build:
	sudo docker-compose -f srcs/docker-compose.yml build

# Démarrer les conteneurs
up: build
	sudo docker-compose -f srcs/docker-compose.yml up -d

# Arrêter les conteneurs
down:
	sudo docker-compose -f srcs/docker-compose.yml down

# Nettoyer les conteneurs, les images, les réseaux et les volumes
clean: down
	sudo docker system prune -af --volumes
	sudo docker volume rm $$(docker volume ls -qf dangling=true)
	sudo rm -rf /home/lmattern/data/wordpress/*
	sudo rm -rf /home/lmattern/data/mariadb/*

# Reconstruire et redémarrer les conteneurs
re: clean up