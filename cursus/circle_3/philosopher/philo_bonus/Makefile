NAME = philo_bonus

SRCS = 	$(wildcard ./*.c)

OBJS = $(SRCS:.c=.o)

RM = rm -rf

INC = philosopher.h

CC = gcc #-fsanitize=address

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
