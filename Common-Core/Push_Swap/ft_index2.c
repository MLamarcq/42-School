/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:11:45 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:11:45 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index2(t_list **lst)
{
	t_list	*tmp;
	t_list	*temp;
	t_list	*tmp1;
	int		index;

	temp = (*lst);
	tmp = (*lst)->next;
	tmp1 = temp;
	index = 1;
	while (temp)
	{
		temp->index = 1;
		while (tmp)
		{
			if (temp->nbr > tmp->nbr)
				temp->index = temp->index + index;
			tmp = tmp->next;
		}
		temp = temp->next;
		tmp = tmp1;
	}
}

int	ft_index_min_2(t_list **lst)
{
	t_list	*tmp;
	int		min;
	int		targ;

	tmp = (*lst);
	min = 2147483647;
	targ = tmp->position;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			targ = tmp->position;
		}
		tmp = tmp->next;
	}
	return (targ);
}
