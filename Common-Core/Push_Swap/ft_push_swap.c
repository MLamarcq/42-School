/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:29:40 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:29:41 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **lst, t_list **lst1, int i)
{
	if (ft_verif(lst) == 0)
		return ;
	if (i == 2 && ft_verif(lst) == 1)
		ft_swap_a(lst);
	if (i == 3 && ft_verif(lst) == 1)
		ft_tri_3(lst);
	if (i > 3 && ft_verif(lst) == 1)
		ft_sort(lst, lst1);
}
