NAME = ft_cat

SRCS = srcs/ft_cat.c

INC = includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INC) 

clean : 
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME)

.PHONY : all clean fclean
