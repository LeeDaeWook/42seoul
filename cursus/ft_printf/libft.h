#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

typedef struct s_flag
{
    int minus;
    int zero;
    int dot;
    int star;
    int width;

}   t_flag;

long long	    ft_len(long long n);
void    print_num(unsigned long long num, char* format, int* ret_val, t_flag *flag);
char    *put_type(char* format, va_list *ap, int* ret_val, t_flag *flag);
int     read_format(char* format, va_list *ap);
int     ft_printf(const char* format, ...);
void	ft_putnbr_base(unsigned long long nbr, int* ret_val, char *format);
void	ft_putnbr_fd_un(unsigned int n, int fd);
void	ft_memset_intptr(void*ptr, int c, size_t len);