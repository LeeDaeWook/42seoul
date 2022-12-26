#include <unistd.h>

int	ft_strlen4(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	exception(char *base)
{
	int		base_len;
	int		j;
	int		i;
	char	target;

	base_len = ft_strlen4(base);
	i = 0;
	if (base_len == 0 || base_len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		target = base[i];
		j = i + 1;
		while (base[j])
		{
			if (target == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_base(char *base, long long lnbr, int base_len)
{
	int	index;

	index = lnbr % base_len;
	if (lnbr / base_len > 0)
		print_base(base, lnbr / base_len, base_len);
	write(1, &base[index], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long		lnbr;
	int				base_len;

	lnbr = (long long)nbr;
	base_len = ft_strlen4(base);
	if (nbr < 0)
	{
		lnbr *= -1;
		write(1, "-", 1);
	}
	if (exception(base) != 0)
		print_base(base, lnbr, base_len);
}
