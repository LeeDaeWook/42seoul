NAME = Megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

CPP = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CPP)  $^ -o $@

%.o: %.c
	$(CPP) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
