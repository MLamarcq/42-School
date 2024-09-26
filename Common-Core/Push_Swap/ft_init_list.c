/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:14:02 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:14:03 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_list(char **argv, t_list **list_a)
{
	int			i;
	long int	nbr;
	t_list		*new;

	i = 1;
	if (ft_check_double(argv) == 1)
		return (1);
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr != 10000000000)
		{
			new = ft_lstnew(nbr);
			if (i == 1)
				*list_a = new;
			else
				ft_lstadd_back(list_a, new);
		}
		else
			return (1);
		i++;
	}
	return (0);
}
