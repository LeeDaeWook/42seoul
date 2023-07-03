NAME = ZombieHorde

SRCS = 	main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SRCS:.c=.o)

RM = rm -rf

INC = Zombie.hpp

CC = c++

CFLAGS = -c -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
