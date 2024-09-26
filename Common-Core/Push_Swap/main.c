/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:54:48 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/10/31 12:55:46 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		i;

	list_a = NULL;
	list_b = NULL;
	i = argc - 1;
	if (argc < 2)
		return (0);
	if (ft_init_list(argv, &list_a) == 1)
	{
		write (2, "Error\n", 6);
		ft_lstclear(&list_a);
		return (0);
	}
	ft_index2(&list_a);
	ft_push_swap(&list_a, &list_b, i);
	ft_lstclear(&list_a);
}
