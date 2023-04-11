NAME = push_swap

NAME_BONUS = checker

SRCS =	push_swap.c			push_swap_second.c	parse.c				push.c\
		rotate.c			reverse_rotate.c	swap.c				print.c\
		greedy.c			fill_count.c		find.c				free.c\
		ft_atoi_ll.c

SRCS_BONUS =	checker.c			get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c\
				parse.c				checker_utils.c					free.c\
				ft_atoi_ll.c		print.c							checker_validate.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar -rcs

RM = rm -f

INC = push_swap.h

INC_BONUS = checker.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

FTPRINTFDIR = ./ft_printf

FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

$(NAME) : $(OBJS) $(LIBFT) $(FTPRINTF)
	$(CC) $^ -o $@

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT) $(FTPRINTF)
	$(CC) $^ -o $@

$(LIBFT) :
	make -C $(LIBFTDIR)

$(FTPRINTF) :
	make -C $(FTPRINTFDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBFTDIR)/*.o $(FTPRINTFDIR)/*.o \
		$(FTPRINTFDIR)/$(LIBFTDIR)/*.o

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT) $(FTPRINTF)

re : fclean all

bonus : $(NAME_BONUS)

.PHONY : all clean fclean re bonus
