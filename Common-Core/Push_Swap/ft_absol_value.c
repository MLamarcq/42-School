/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absol_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:54:25 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 10:54:45 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_absol_value(int nbr)
{
	if (nbr == 0)
		nbr = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr > 0)
		nbr = nbr;
	return (nbr);
}
