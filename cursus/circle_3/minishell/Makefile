NAME = minishell
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
SRCS = minishell.c minishell_utils.c $(wildcard src/parse/list/*.c) $(wildcard src/*.c) $(wildcard src/built_in/*.c)\
	   $(wildcard src/excute/*.c) $(wildcard src/gnl/*.c) $(wildcard src/parse/*.c)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) ./$(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline -L ~/.brew/opt/readline/lib

$(LIBFT) :
	make -C $(LIBFT_DIR) bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ~/.brew/opt/readline/include -I ./include

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re