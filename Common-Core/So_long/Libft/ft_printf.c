#include "libft.h"

int	ft_format(va_list arg, unsigned char c)
{
	size_t nb;

	nb = 0;
	if (c == 'c')
		nb += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		nb += ft_putstr(va_arg(arg, char*));
	else if ((c =='d') || (c == 'i'))
		nb += ft_print_nb(va_arg(arg, int));
	else if (c == 'u')
		nb += ft_print_unsigned_nb(va_arg(arg, unsigned int));
	else if (c == 'x')
		nb += ft_print_little_x(va_arg(arg, unsigned int));
	else if (c == 'X')
		nb += ft_print_big_x(va_arg(arg, unsigned int));
	else if (c == 'p')
		nb += ft_print_pointer(va_arg(arg, unsigned long long int));
	else if (c == '%')
		nb += ft_print_purcent();
	return (nb);
}

int	ft_printf(const char *str, ...)
{
	va_list arg;
	int i;
	int nb;

	va_start(arg, str);
	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			nb += ft_format(arg, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			nb++;
		}
		i++;
	}
	va_end(arg);
	return (nb);
}
