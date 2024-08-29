/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:19:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/26 13:30:08 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_itoa_len(int n)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * (-1);
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_itoa_len(n);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		dest[0] = '-';
	}
	while (nbr >= 10)
	{
		dest[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	dest[len--] = nbr + '0';
	return (dest);
}
/*
int	main()
{
	int	test = -124;
	printf("%s\n", ft_itoa(test));
	printf("%s\n", itoa(test));
	return (0);
}*/