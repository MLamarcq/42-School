/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:34 by mlamarcq          #+#    #+#             */
/*   Updated: 2023/01/05 13:07:34 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:12 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:12 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nbr_of_line(t_shape *shp, char *file)
{
	shp->fd = open(file, O_RDONLY);
	if (shp->fd == -1)
	{
		write (2, "Error : File does not exist\n", 28);
		write (2, "You should create some file by yourself\n", 40);
		exit (1);
	}
	else
	{
		shp->tmp = "";
		shp->y = 0;
		while (shp->tmp != NULL)
		{
			shp->tmp = get_next_line(shp->fd);
			if (shp->tmp == NULL)
				break ;
			shp->y++;
			free(shp->tmp);
		}
	}
	close(shp->fd);
	return (shp->y);
}

char	**ft_initmap(t_shape *shp, char *file)
{
	int	i;

	shp->y = ft_nbr_of_line(shp, file);
	if (shp->y == 0)
		return (NULL);
	shp->final = (char **)malloc(sizeof(char *) * (shp->y + 1));
	if (!shp->final)
		return (NULL);
	shp->final[shp->y] = 0;
	shp->fd = open(file, O_RDONLY);
	if (shp->fd == -1)
		return (NULL);
	else
	{
		i = 0;
		while (i < shp->y)
		{
			shp->final[i] = get_next_line(shp->fd);
			i++;
		}
	}
	close (shp->fd);
	return (shp->final);
}
