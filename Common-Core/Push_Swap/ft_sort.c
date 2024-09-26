/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:32:13 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:59:38 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **lst, t_list **lst1)
{
	int	i;

	ft_nbr_3_lst_a(lst, lst1);
	i = ft_lstsize2(lst1);
	while (i > 0)
	{
		ft_target_pos2(lst, lst1);
		ft_cost(lst, lst1);
		ft_do_mouv(lst1, lst);
		i--;
	}
	if (ft_verif(lst) == 1)
		ft_last_move(lst);
}
