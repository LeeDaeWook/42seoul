#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    
    int fd = open("./abc.txt", O_RDONLY);
    printf("%s", get_next_line(fd));

    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));


    // int fd2 = open("./abd.txt", O_RDONLY);
    // printf("%s", get_next_line(fd2));
    // printf("%s", get_next_line(fd2));
    // printf("%s", get_next_line(fd2));

    //system("leaks a.out");
    return 0;
}