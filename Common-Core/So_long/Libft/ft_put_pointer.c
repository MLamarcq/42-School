#include "libft.h"

void	ft_put_pointer(unsigned long long int nb)
{
	char	*str;

	str = "0123456789abcdef";

	if(nb >= 16)
	{
		ft_put_pointer(nb / 16);
		ft_put_pointer(nb % 16);
	}
	else
	{
		ft_putchar(str[nb]);
	}
}

int	ft_hexa_len_long(unsigned long long int nb)
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
}

int	ft_print_pointer(unsigned long long int nb)
{
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_put_pointer(nb);
	return (ft_hexa_len_long(nb) + 2);
}