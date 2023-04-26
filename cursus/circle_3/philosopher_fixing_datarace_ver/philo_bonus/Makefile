NAME = philo_bonus

SRCS = 	fork.c ft_atoi.c ft_strcmp.c main.c philosopher.c set.c utils.c 

OBJS = $(SRCS:.c=.o)

RM = rm -rf

INC = philosopher.h

CC = cc

CFLAGS = -c -Wall -Wextra -Werror

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
