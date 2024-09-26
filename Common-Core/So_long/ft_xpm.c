/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:57:32 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 14:57:32 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xpm(t_shape *shp)
{
	shp->O = NULL;
	shp->L = NULL;
	shp->E = NULL;
	shp->P = NULL;
	shp->C = NULL;
}

int	ft_xpm_to_image(t_shape *shp)
{
	ft_init_xpm(shp);
	shp->O = mlx_xpm_file_to_image(shp->mlx_ptr, "./image/Floor.xpm", \
	&shp->size, &shp->size);
	if (shp->O == NULL)
		return (0);
	shp->L = mlx_xpm_file_to_image(shp->mlx_ptr, "./image/Wall.xpm", \
	&shp->size, &shp->size);
	if (shp->L == NULL)
		return (0);
	shp->E = mlx_xpm_file_to_image(shp->mlx_ptr, "./image/Exit.xpm", \
	&shp->size, &shp->size);
	if (shp->E == NULL)
		return (0);
	shp->P = mlx_xpm_file_to_image(shp->mlx_ptr, "./image/Caracter.xpm", \
	&shp->size, &shp->size);
	if (shp->P == NULL)
		return (0);
	shp->C = mlx_xpm_file_to_image(shp->mlx_ptr, "./image/Item.xpm", \
	&shp->size, &shp->size);
	if (shp->C == NULL)
		return (0);
	return (1);
}

void	ft_destroy_image_xpm(t_shape *shp)
{
	if (shp->O != NULL)
		mlx_destroy_image(shp->mlx_ptr, shp->O);
	if (shp->L != NULL)
		mlx_destroy_image(shp->mlx_ptr, shp->L);
	if (shp->E != NULL)
		mlx_destroy_image(shp->mlx_ptr, shp->E);
	if (shp->P != NULL)
		mlx_destroy_image(shp->mlx_ptr, shp->P);
	if (shp->C != NULL)
		mlx_destroy_image(shp->mlx_ptr, shp->C);
	ft_free_str(shp->final);
	mlx_destroy_display(shp->mlx_ptr);
	free(shp->mlx_ptr);
	write(2, "Image Failure\n", 14);
	exit(1);
}

int	ft_xpm(t_shape *shp)
{
	if (ft_xpm_to_image(shp) == 0)
	{
		ft_destroy_image_xpm(shp);
		return (0);
	}
	return (1);
}
