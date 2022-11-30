TARGET = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

INC = includes/ft.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar -cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
