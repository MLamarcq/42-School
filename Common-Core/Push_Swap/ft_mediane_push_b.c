/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:26:29 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:26:29 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mediane_push_b(t_list **lst, t_list **lst2)
{
	t_list	*tmp;
	t_list	*temp;
	int		mediane;
	int		i;

	i = ft_lstsize2(lst);
	mediane = i / 2;
	tmp = (*lst);
	temp = tmp->next;
	if (i == 4)
		mediane = mediane - 1;
	ft_index2(lst);
	if (i == 3)
		return ;
	while (i > 0)
	{
		if (tmp->index <= mediane)
			ft_push_b(lst2, lst);
		else
			ft_lst_rotate_a(lst);
		tmp = temp;
		temp = temp->next;
		i--;
	}
}
