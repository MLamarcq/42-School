/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_3_lst_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:27:23 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:27:24 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nbr_3_lst_a(t_list **lst1, t_list **lst2)
{
	int	i;

	ft_mediane_push_b(lst1, lst2);
	i = ft_lstsize2(lst1);
	if (i == 3)
	{
		ft_tri_3(lst1);
		return ;
	}
	while (i > 3)
	{
		ft_push_b(lst2, lst1);
		i--;
	}
	ft_tri_3(lst1);
}
