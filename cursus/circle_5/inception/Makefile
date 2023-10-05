HOST_VOLUME := /home/daewoole/data

all :	
	mkdir -p $(HOST_VOLUME)/mariadb
	mkdir -p $(HOST_VOLUME)/wordpress
	docker compose -f srcs/docker-compose.yml build --no-cache

up :
	docker compose -f srcs/docker-compose.yml up -d

down :
	docker compose -f srcs/docker-compose.yml down
	
clean : down
	docker system prune -f -all

fclean : clean
	sudo rm -rf $(HOST_VOLUME)/db/*
	sudo rm -rf $(HOST_VOLUME)/wordpress/*

re : fclean all

.PHONY : all clean fclean re