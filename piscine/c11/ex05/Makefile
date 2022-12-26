NAME = do-op

SRCS = srcs/ft_atoi.c srcs/ft_putnbr.c srcs/calc.c srcs/do_op.c

OBJS = $(SRCS:.c=.o)

INC = includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INC) 

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
