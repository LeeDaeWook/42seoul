#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("./abc.txt", O_RDONLY);
    printf("%s", get_next_line(fd));

    return 0;
}