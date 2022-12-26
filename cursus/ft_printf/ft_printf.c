
#include "libft.h"
#include <stdio.h>

long long	ft_len(long long n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	else
		i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_memset_intptr(void*ptr, int c, size_t len)
{
    size_t	i;
	int	    *int_ptr;

	i = 0;
	int_ptr = (int*)ptr;
	while (i < len)
		int_ptr[i++] = (unsigned char)c;
}

void    print_char(int c, char* format, int* ret_val)
{
    ft_putchar_fd(c, 1);
    *ret_val += 1;
}

void    excute_width(int *ret_val, t_flag *flag, unsigned long long num)
{
    int c;
    size_t len;

    if (flag->width == 0 || flag->minus == 1 || ft_len(num) >= flag->width)
        return ;
    len = width - ft_len(num);
    if (flag->zero == 1)
        c = '0';
    else
        c = ' ';
    while (len > 0)
    {
        write(1, &c, 1);
        len--;
    }
}

void    excute_flag(char *format, int* ret_val, t_flag *flag)
{
    if (flag->minus == 1)
        return ;
    else if (flag->zero == 1 && flag->minus != 1)
        return ;
    //else if (flag->dot == 1)
    else if (flag->star == 1)

}

void    print_num(unsigned long long num, char* format, int* ret_val, t_flag *flag)
{
    if (*format == 'd' || *format == 'i')
    {
        excute_flag(format, ret_val, flag);
        excute_width(ret_val, flag, num);
        ft_putnbr_fd(num, 1);
        *ret_val += flag->width;
    }
    else if (*format == 'u')
    {
        ft_putnbr_fd_un(num, 1);
        *ret_val += ft_len(num);
    }
    else if (*format == 'p' || *format == 'x' || *format == 'X')
    {
        if (*format == 'p')
            *ret_val += write(1, "0x", 2); // hard coding...
        ft_putnbr_base(num, ret_val, format);
    }
}

void    print_str(char* str, char *format, int *ret_val)
{
    ft_putstr_fd(str, 1);
    *ret_val += ft_strlen(str);
}

char    *get_width(char *format, int *ret_val, t_flag *flag)
{
    flag->width = ft_atoi(format);
    while (*format >= '0' && *format <= '9') // 맨 앞 숫자를 제외하고는 뒤에 0이 나올 수 있음
        format++;

    return (format);
}

char    *put_type(char* format, va_list *ap, int* ret_val, t_flag *flag)
{
    if (*format == 'c')
        print_char(va_arg(*ap, int), format, ret_val); // char is needed to promoted to int
    else if (*format == 's')
        print_str(va_arg(*ap, char*), format, ret_val);
    else if (*format == 'p')
        print_num((unsigned long long)va_arg(*ap, void*), format, ret_val, flag);
    else if (*format == 'd' || *format == 'i')
        print_num(va_arg(*ap, int), format, ret_val, flag);
    else if (*format == 'u' || *format == 'x' || *format == 'X')
        print_num(va_arg(*ap, unsigned int), format, ret_val, flag);
    else if (*format == '%')
        print_char('%', format, ret_val);

    format++;
    return (format);
}

char    *search_option(char *format, va_list *ap, int *ret_val)
{
    t_flag *flag;

    flag = (t_flag*)malloc(sizeof(t_flag) * 1);
    ft_memset_intptr((void*)flag, 0, sizeof(flag) / 4); // hard coding...
    while (*format < '1' || *format > '9')
    {
        if (*format == '-')
            flag->minus = 1; 
        else if (*format == '0')
            flag->zero = 1;
        else if (*format == '.')
            flag->dot = 1;
        else if (*format == '*')
            flag->star = 1;
        format++;
    }
    if (*format >= '1' && *format <= '9')
        format = get_width(format, ret_val, flag);
    
    format = put_type(format, ap, ret_val, flag);
    
    free(flag);
    return (format);
}

int read_format(char* format, va_list *ap)
{
    int ret_val;

    ret_val = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            format = search_option(format, ap, &ret_val);
        }
        else
        {
            ft_putchar_fd(*format, 1); // format specifier 이외의 것들에 대해
            format++;
            ret_val++;
        }
    }
    return (ret_val);
}

int ft_printf(const char* format, ...)
{
    va_list ap;
    int ret_val;

    va_start(ap, format);

    ret_val = read_format((char*)format, &ap);

    va_end(ap);
    return (ret_val);
}