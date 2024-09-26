/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:06:59 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/11/14 14:07:01 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_list **lst, t_list **lst1)
{
	t_list	*temp;
	int		i;
	int		j;

	temp = (*lst1);
	i = ft_lstsize2(lst);
	j = ft_lstsize2(lst1);
	while (temp)
	{
		if (temp->position <= j / 2)
			temp->cost_b = temp->position;
		else
			temp->cost_b = (j - temp->position) * -1;
		if (temp->target_pos <= i / 2)
			temp->cost_a = temp->target_pos;
		else
			temp->cost_a = (i - temp->target_pos) * -1;
		temp = temp->next;
	}
}

void	ft_costa_mouv(t_list **lst, int i)
{
	while (i > 0)
	{
		ft_lst_rotate_a(lst);
		i--;
	}
	while (i < 0)
	{
		ft_lst_reverse_a(lst);
		i++;
	}
}

void	ft_costb_mouv(t_list **lst, int i)
{
	while (i > 0)
	{
		ft_lst_rotate_b(lst);
		i--;
	}
	while (i < 0)
	{
		ft_lst_reverse_b(lst);
		i++;
	}
}

void	ft_exct_mouv(t_list **lst, t_list **lst1, int i, int j)
{
	while ((i > 0 && j > 0))
	{
		ft_double_rotate(lst, lst1);
		i--;
		j--;
	}
	while ((i < 0 && j < 0))
	{
		ft_lst_double_reverse(lst, lst1);
		i++;
		j++;
	}
	ft_costa_mouv(lst1, i);
	ft_costb_mouv(lst, j);
	ft_push_a(lst1, lst);
}
