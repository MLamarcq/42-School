/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:55:53 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 10:55:54 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	long int	i;
	long int	j;
	long int	k;
	long int	sign;

	i = 0;
	sign = 1;
	if (str[0] == '\0')
		return (10000000000);
	if ((str[i] == 45 || str [i] == 43) && str[i + 1] != '\0')
	{
		if (str[i++] == 45)
			sign = sign * (-1);
	}
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	k = (j * sign);
	if (str[i] != '\0' || k > 2147483647 || k < -2147483648)
		return (10000000000);
	return (k);
}
