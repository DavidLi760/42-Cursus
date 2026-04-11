DOCKER_COMPOSE_FILE = srcs/docker-compose.yml
DATABASE_VOLUME = /home/davli/data/mysql
WORDPRESS_VOLUME = /home/davli/data/wordpress
DATABASE_DOCKER_VOLUME = srcs_mariadb_v
WORDPRESS_DOCKER_VOLUME = srcs_wordpress_v
MKDIR = mkdir -p
RM = rm -rf

all: up

up:
	sudo $(MKDIR) $(DATABASE_VOLUME)
	sudo $(MKDIR) $(WORDPRESS_VOLUME)
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) up --build -d

down:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) down

stop:
	sudo docker-compose -f $(DOCKER_COMPOSE_FILE) stop

clean: down
	sudo docker container prune --force

fclean: clean
	sudo $(RM) $(DATABASE_VOLUME)
	sudo $(RM) $(WORDPRESS_VOLUME)
	sudo docker system prune --all --force
	sudo docker volume rm $(DATABASE_DOCKER_VOLUME) $(WORDPRESS_DOCKER_VOLUME)

re: fclean all

.PHONY: all volume up down clean fclean re
