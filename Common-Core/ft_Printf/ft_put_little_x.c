#include "libftprintf.h"

void	ft_put_little_x(unsigned int nb)
{
	char *str;

	str = "0123456789abcdef";

	if (nb >= 16)
	{
		ft_put_little_x(nb / 16);
		ft_put_little_x(nb % 16);
	}
	else
	{
		ft_putchar(str[nb]);
	}
}

/*int	ft_hexa_len(unsigned int nb)
{
	size_t len;

	len = 0;
	if (nb == 0)
	{
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}*/

int	ft_print_little_x(unsigned int nb)
{
	ft_put_little_x(nb);
	return (ft_hexa_len(nb));
}