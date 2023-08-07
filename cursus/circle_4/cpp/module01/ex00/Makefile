NAME = Zombie

SRCS = 	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 

OBJS = $(SRCS:.cpp=.o)

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
