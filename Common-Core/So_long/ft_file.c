/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:07 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:07 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file(char *file)
{
	int		i;
	int		j;
	char	*dest;

	i = ft_strlen(file);
	if (i < 4)
		return (0);
	j = i - 4;
	i = 0;
	dest = (char *)malloc(sizeof(char) * 4 + 1);
	while (file[j])
	{
		dest[i] = file[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (ft_strncmp(dest, ".ber", 4) != 0)
	{
		free(dest);
		return (2);
	}
	free(dest);
	return (1);
}

int	ft_file_error(char *file)
{
	if (ft_file(file) == 0)
	{
		ft_printf("Error : You need a minimum of 4 char for your extension\n");
		return (0);
	}
	else if (ft_file(file) == 2)
	{
		write (2, "Error : Your extension has to be .ber\n", 38);
		return (0);
	}
	return (1);
}
