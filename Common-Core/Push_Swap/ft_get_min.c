/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:09:48 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:09:49 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_list **lst)
{
	t_list	*tmp;
	int		total;
	int		min;

	tmp = (*lst);
	min = 2147483647;
	while (tmp)
	{
		total = ft_absol_value(tmp->cost_a) + ft_absol_value(tmp->cost_b);
		if (total < min)
			min = total;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_do_mouv(t_list **lst, t_list **lst1)
{
	t_list	*tmp;
	int		result;
	int		min;

	min = ft_get_min(lst);
	tmp = (*lst);
	while (tmp)
	{
		result = ft_absol_value(tmp->cost_b) + ft_absol_value (tmp->cost_a);
		if (result == min)
		{
			ft_exct_mouv(lst, lst1, tmp->cost_a, tmp->cost_b);
			break ;
		}
		tmp = tmp->next;
	}
}
