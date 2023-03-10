NAME = push_swap.a

SRCS = 	push_swap.c		push_swap_second.c	parse.c		push.c\
		rotate.c		reverse_rotate.c	swap.c		print.c\
		greedy.c		fill_count.c		find.c		free.c just.c

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

RM = rm -f

INC = libft.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
