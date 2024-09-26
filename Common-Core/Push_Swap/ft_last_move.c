/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:15:01 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:15:01 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst);
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_last_move(t_list **lst)
{
	int	size;
	int	low_pos;

	size = ft_lstsize2(lst);
	low_pos = ft_index_min_2(lst);
	if (low_pos > size / 2)
	{
		while (low_pos < size)
		{
			ft_lst_reverse_a(lst);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			ft_lst_rotate_a(lst);
			low_pos--;
		}
	}
}
