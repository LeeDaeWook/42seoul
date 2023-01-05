
#include "ft_printf.h"

long long	ft_len(long long n)
{
	int	i;

    if (n == 0)
        return (1);
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

char    *put_type(char* format, va_list *ap, int* ret_val)
{
    if (*format == 'c')
        ft_print_char(va_arg(*ap, int), ret_val); // char is needed to promoted to int
    else if (*format == 's')
        ft_print_str(va_arg(*ap, char*), ret_val);
    else if (*format == 'p')
        ft_print_num((unsigned long long)va_arg(*ap, void*), format, ret_val);
    else if (*format == 'd' || *format == 'i')
        ft_print_num(va_arg(*ap, int), format, ret_val);
    else if (*format == 'u' || *format == 'x' || *format == 'X')
        ft_print_num(va_arg(*ap, unsigned int), format, ret_val);
    else if (*format == '%')
        ft_print_char('%', ret_val);

    format++;
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
            format = put_type(format, ap, &ret_val);
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