NAME = libft.a

SRCS = 	ft_atoi.c	        ft_memset.c		ft_strlcpy.c		ft_bzero.c	    \
	ft_putchar_fd.c 	ft_strlen.c		ft_calloc.c   		ft_putendl_fd.c	    \
	ft_strmapi.c		ft_isalnum.c  		ft_putnbr_fd.c		ft_strncmp.c	    \
	ft_isalpha.c  		ft_putstr_fd.c		ft_strnstr.c		ft_isascii.c	    \
	ft_split.c		ft_strrchr.c		ft_isdigit.c  		ft_strchr.c         \
	ft_strstr.c		ft_isprint.c  		ft_memchr.c		ft_strdup.c         \
	ft_strtrim.c		ft_itoa.c	   	ft_memcmp.c		ft_striteri.c  	    \
	ft_substr.c      	ft_memcpy.c   		ft_strjoin.c		ft_tolower.c        \
	ft_memmove.c		ft_strlcat.c  		ft_toupper.c

SRCS_B = ft_lstclear.c		ft_lstdelone.c		ft_lstiter.c		ft_lstlast.c	    \
	 ft_lstmap.c		ft_lstnew.c		ft_lstsize.c     	ft_lstadd_back.c    \
	 ft_lstadd_front.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

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

bonus : $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $^

.PHONY : all clean fclean re bonus
