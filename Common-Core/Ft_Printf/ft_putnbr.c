#include "libftprintf.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483647)
	{
		write(1, "-2147483647", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb <= 9)
	{
		nb = nb + '0';
		ft_putchar(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_putnbr_len(int nb)
{
	size_t len;
	
	len = 0;
	if (nb == 0)
	{
		len++;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_print_nb(int nb)
{
	ft_putnbr(nb);
	return (ft_putnbr_len(nb));
}
/*
int	main()
{
	ft_print_nb(559);
	write(1, "\n", 1);
	return (0);
}*/