/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_3_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:37 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 11:42:37 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_sa(t_list **lst)
{
	ft_lst_rotate_a(lst);
	ft_swap_a(lst);
}

void	ft_rra_sa(t_list **lst)
{
	ft_lst_reverse_a(lst);
	ft_swap_a(lst);
}

void	ft_ra_recurs(t_list **lst)
{
	ft_lst_rotate_a(lst);
	ft_tri_3(lst);
}
