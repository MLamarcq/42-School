/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:56:29 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 10:56:29 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_double(char **str)
{
	int			i;
	int			j;
	long int	k;
	long int	l;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			k = ft_atoi(str[i]);
			l = ft_atoi(str[j]);
			if (k == l)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
