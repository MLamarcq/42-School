/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:30:55 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:30:55 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_list **lst_b, t_list **lst_a)
{
	t_list	*elema;

	if ((*lst_a) == NULL)
		return ;
	elema = (*lst_a)->next;
	ft_lstadd_front(lst_b, (*lst_a));
	(*lst_a) = elema;
	write(1, "pb\n", 3);
	ft_position2(lst_a);
	ft_position2(lst_b);
}

void	ft_push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*elemb;

	if ((*lst_b) == NULL)
		return ;
	elemb = (*lst_b)->next;
	ft_lstadd_front(lst_a, (*lst_b));
	(*lst_b) = elemb;
	write(1, "pa\n", 3);
	ft_position2(lst_a);
	ft_position2(lst_b);
}
