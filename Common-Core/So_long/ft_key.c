/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:15:44 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 13:15:44 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_release(int key, t_shape *shp)
{
	if (key == XK_Escape)
		ft_free_all(shp);
	return (0);
}

int	ft_key_press(int key, t_shape *shp)
{
	int	i;

	i = shp->move;
	if (key == XK_w || key == XK_W)
		shp->move = shp->move + ft_move_map(shp, 'U');
	if (key == XK_a || key == XK_A)
		shp->move = shp->move + ft_move_map(shp, 'L');
	if (key == XK_d || key == XK_D)
		shp->move = shp->move + ft_move_map(shp, 'R');
	if (key == XK_s || key == XK_S)
		shp->move = shp->move + ft_move_map(shp, 'D');
	if (i != shp->move)
		ft_printf("Number of movement = %d\n", shp->move);
	return (0);
}

void	ft_config(t_shape *shp, char *file)
{
	ft_initmap(shp, file);
	shp->mlx_ptr = mlx_init();
	if (!shp->mlx_ptr)
		return ;
	shp->size = 48;
	ft_xpm(shp);
	shp->win_ptr = mlx_new_window(shp->mlx_ptr, (shp->size * (shp->x - 1)), \
	(shp->size * shp->y), "SO_LONG");
	if (!shp->win_ptr)
	{
		ft_free_all(shp);
		return ;
	}
	ft_put_image(shp);
	mlx_hook(shp->win_ptr, 3, KeyReleaseMask, &ft_key_release, shp);
	mlx_hook(shp->win_ptr, 2, KeyPressMask, &ft_key_press, shp);
	mlx_hook(shp->win_ptr, 17, StructureNotifyMask, &ft_free_all, shp);
	mlx_loop(shp->mlx_ptr);
}
