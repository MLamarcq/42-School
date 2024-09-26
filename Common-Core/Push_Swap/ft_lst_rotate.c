/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:18:45 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:18:46 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = (*lst);
	temp = (*lst)->next;
	ft_lstlast(lst);
	(*lst)->next = tmp;
	tmp->next = NULL;
	(*lst) = temp;
}

void	ft_lst_rotate_a(t_list **lst)
{
	ft_lst_rotate(lst);
	write(1, "ra\n", 3);
	ft_position2(lst);
}

void	ft_lst_rotate_b(t_list **lst)
{
	ft_lst_rotate(lst);
	write(1, "rb\n", 3);
	ft_position2(lst);
}

void	ft_double_rotate(t_list **lst, t_list **lst2)
{
	ft_lst_rotate(lst);
	ft_lst_rotate(lst2);
	write(1, "rr\n", 3);
	ft_position2(lst);
	ft_position2(lst2);
}
