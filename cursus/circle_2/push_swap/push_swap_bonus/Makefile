NAME = push_swap

SRCS =	push_swap.c		push_swap_second.c	parse.c		push.c\
		rotate.c		reverse_rotate.c	swap.c		print.c\
		greedy.c		fill_count.c		find.c		free.c just.c

# SRCS_BONUS

OBJS = $(SRCS:.c=.o)

# OBJS_BONUS = $(SRCS_S_BONUS:.c=.o)

AR = ar -rcs

RM = rm -f

INC = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

FTPRINTFDIR = ./ft_printf

FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

$(NAME) : $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $^ -o $@

$(LIBFT) :
	make -C $(LIBFTDIR)

$(FTPRINTF) :
	make -C $(FTPRINTFDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(LIBFTDIR)/*.o $(FTPRINTFDIR)/*.o

fclean : clean
	$(RM) $(NAME) $(LIBFT) $(FTPRINTF)

re : fclean all

# bonus :
	# make SRCS_S="$(SRCS_BONUS)" INC="push_swap_bonus.h" all

.PHONY : all clean fclean re bonus
