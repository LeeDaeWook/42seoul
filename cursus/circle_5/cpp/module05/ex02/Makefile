NAME = ex02

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

CXX = c++

CXXFLAGS = -c -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
