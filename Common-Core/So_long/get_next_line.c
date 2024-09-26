/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:23:48 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:23:48 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			i;
	char		*str;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = NULL;
	if (ft_strlen(buffer) != 0)
		str = ft_strdup(buffer);
	while (!(ft_strchr(buffer, '\n')))
	{	
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buffer[i] = '\0';
		if (i == 0)
			return (ft_strjoin(str, buffer));
		if (str == NULL)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
	}
	if (!str)
		return (free (str), NULL);
	return (ft_keep_line(str, buffer), str);
}
