NAME = fractol

SRCS = 	main.c burningship.c draw.c julia.c mandelbrot.c \
keyboard_hook.c mouse_hook.c utils.c

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

RM = rm -f

INC = fractol.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIB = libft.a

$(NAME) : $(OBJS) $(LIB)
	$(CC) $^ -o $@ ${MLXFLAGS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
