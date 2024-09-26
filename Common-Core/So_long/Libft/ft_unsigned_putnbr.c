#include "libft.h"

void	ft_unsigned_putnbr(unsigned int nb)
{
	if (nb <= 9)
	{
		nb = nb + '0';
		ft_putchar(nb);
	}
	else 
	{
		ft_unsigned_putnbr(nb / 10);
		ft_unsigned_putnbr(nb % 10);
	}
}

int	ft_unsigned_putnbr_len(unsigned int nb)
{
	size_t len;

	len = 0;
	if(nb == 0)
	{
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned_nb(unsigned int nb)
{
	ft_unsigned_putnbr(nb);
	return (ft_unsigned_putnbr_len(nb));
}