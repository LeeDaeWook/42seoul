NAME_S = server

NAME_C = client

SRCS_S = server.c

SRCS_S_BONUS = server_bonus.c

SRCS_C = client.c

SRCS_C_BONUS = client_bonus.c

OBJS_S = $(SRCS_S:.c=.o)

OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)

AR = ar -rcs

RM = rm -f

INC = minitalk.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

FTPRINTFDIR = ./ft_printf

FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

$(LIBFT) :
	make -C $(LIBFTDIR)

$(FTPRINTF) :
	make -C $(FTPRINTFDIR)

$(NAME_S) : $(OBJS_S) $(LIBFT) $(FTPRINTF)
	$(CC) $^ -o $@

$(NAME_C) : $(OBJS_C) $(LIBFT) $(FTPRINTF)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

all : $(NAME_S) $(NAME_C)

clean :
	$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_S_BONUS) $(OBJS_C_BONUS)

fclean : clean
	$(RM) $(NAME_S) $(NAME_C)

re : fclean all

bonus :
	make SRCS_S="$(SRCS_S_BONUS)" SRCS_C="$(SRCS_C_BONUS)" all

.PHONY : all clean fclean re bonus
