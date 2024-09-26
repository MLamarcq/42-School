/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:38:37 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:39:41 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst);
	tmp1 = (*lst)->next;
	tmp->next = tmp1->next;
	tmp1->next = tmp;
	(*lst) = tmp1;
	(*lst)->next = tmp;
}

void	ft_swap_a(t_list **lst)
{
	ft_swap_list(lst);
	write(1, "sa\n", 3);
	ft_position2(lst);
}

void	ft_swap_b(t_list **lst)
{
	ft_swap_list(lst);
	write(1, "sb\n", 3);
	ft_position2(lst);
}

void	ft_double_swap(t_list **lst, t_list **lst2)
{
	if (lst)
		ft_swap_list(lst);
	if (lst2)
		ft_swap_list(lst2);
	write(1, "ss\n", 3);
	ft_position2(lst);
	ft_position2(lst2);
}
