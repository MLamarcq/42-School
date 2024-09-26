/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:43:40 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:43:40 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tri_3(t_list **lst)
{
	t_list	*tmp;
	t_list	*temp;
	t_list	*tmp1;

	tmp = (*lst);
	temp = tmp->next;
	tmp1 = tmp->next->next;
	if (tmp->index > temp->index && temp->index < tmp1->index)
		ft_ra_recurs(lst);
	else if (tmp->index > temp->index && temp->index > tmp1->index)
		ft_ra_sa(lst);
	else if (tmp->index < temp->index && tmp->index > tmp1->index)
		ft_lst_reverse_a(lst);
	else if (tmp->index > temp->index && tmp->index < tmp1->index)
		ft_swap_a(lst);
	else if (tmp->index < temp->index && tmp->index > tmp1->index)
		ft_lst_reverse_a(lst);
	else if (tmp->index < temp->index && temp->index > tmp1->index)
		ft_rra_sa(lst);
}
