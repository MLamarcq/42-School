/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:17:26 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:17:52 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_reverse(t_list **lst)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = (*lst);
	ft_lst_prevlast(lst);
	temp = (*lst);
	ft_lstlast(lst);
	(*lst)->next = tmp;
	temp->next = NULL;
}

void	ft_lst_reverse_a(t_list **lst)
{
	ft_lst_reverse(lst);
	write(1, "rra\n", 4);
	ft_position2(lst);
}

void	ft_lst_reverse_b(t_list **lst)
{
	ft_lst_reverse(lst);
	write(1, "rrb\n", 4);
	ft_position2(lst);
}

void	ft_lst_double_reverse(t_list **lst, t_list **lst2)
{
	ft_lst_reverse(lst);
	ft_lst_reverse(lst2);
	write(1, "rrr\n", 4);
	ft_position2(lst);
	ft_position2(lst2);
}
