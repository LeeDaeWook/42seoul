NAME = Intern

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

TEXTS = *_shrubbery

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
	$(RM) $(NAME) $(TEXTS)

re : fclean all

.PHONY : all clean fclean re
