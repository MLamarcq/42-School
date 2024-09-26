/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:57 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:57 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_shape	shp;

	(void)argv;
	if (argc == 2)
	{
		if (ft_check_error(&shp, argv[1]) == 0)
			return (0);
		ft_config(&shp, argv[1]);
	}
	else
	{
		write (2, "You have to excute the program with 2 arguments !\n", 50);
		write (2, "This is how it should be : ./so_long file.ber\n", 47);
	}
	return (0);
}
