/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:41:46 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:41:46 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target_pos2(t_list **lst, t_list **lst1)
{
	t_list	*b;
	t_list	*a;
	int		max;

	b = (*lst1);
	while (b)
	{
		max = 2147483647;
		a = (*lst);
		while (a)
		{
			if (b->index < a->index && a->index < max)
			{
				max = a->index;
				b->target_pos = a->position;
			}
			a = a->next;
		}
		if (max == 2147483647)
			b->target_pos = ft_index_min_2(lst);
		b = b->next;
	}
}
