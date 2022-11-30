TARGET = ft_display_file

SRCS = srcs/ft_display_file.c

INC = includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INC) 

clean :
	rm -rf $(TARGET)

re : clean all

.PHONY : all clean re
