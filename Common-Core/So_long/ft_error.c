/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:04 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:04 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_shape(t_shape *shp, char *file)
{
	if (ft_size_verif(shp) == 0)
	{
		ft_free_str(shp->final);
		return (0);
	}
	else if (ft_rect_shp(shp) != 1 || ft_rect_shp_2(shp) != 1)
	{
		write(2, "Error : wrong map shape\n", 24);
		write(2, "Advice : must be a rectangle\n", 29);
		ft_free_str(shp->final);
		return (0);
	}
	else if (ft_wall(shp, file, '1') != 1)
	{
		write(2, "Error : there is a hole in wall\n", 32);
		ft_free_str(shp->final);
		return (0);
	}
	return (1);
}

int	ft_error_map(t_shape *shp)
{
	if (ft_map(shp, 'C', 'P', 'E') == 0)
	{
		write(2, "Error : You can not have more than 1 caracter or exit\n", 54);
		ft_free_str(shp->final);
		return (0);
	}
	else if (ft_map(shp, 'C', 'P', 'E') == 2)
	{
		write(2, "Error : You must have 1 caracter, 1 item and 1 exit\n", 52);
		ft_free_str(shp->final);
		return (0);
	}
	else if (ft_check_map(shp, 'C', 'P', 'E') == 0)
	{
		write(2, "Error : Invalid character\n", 26);
		write(2, "Advice : are allowed P, E, C, 1 and 0\n", 38);
		ft_free_str(shp->final);
		return (0);
	}
	return (1);
}

int	ft_error_game(t_shape *shp)
{
	if (ft_check_e(shp, 'P', 'E') == 0)
	{
		write (2, "Error : You can't play, your exit is not reachable !\n", 53);
		ft_free_str(shp->final);
		return (0);
	}
	else if (ft_check_item(shp) == 0)
	{
		write(2, "Error : your item(s) is (are) not collectible !\n", 48);
		ft_free_str(shp->final);
		return (0);
	}
	return (1);
}

int	ft_check_error(t_shape *shp, char *file)
{
	if (ft_file_error(file) == 0)
		return (0);
	if (ft_initmap(shp, file) == NULL)
	{
		write (2, "Error : empty map !\n", 20);
		return (0);
	}
	if (ft_error_shape(shp, file) == 0)
		return (0);
	else if (ft_error_map(shp) == 0)
		return (0);
	else if (ft_error_game(shp) == 0)
		return (0);
	return (1);
}
