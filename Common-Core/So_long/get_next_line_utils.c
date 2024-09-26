/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:21:35 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/12/08 13:21:35 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{	
	size_t	i;

	if (c == 0)
		return ((char *)str + ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	unsigned int		i;
	unsigned int		j;
	char				*dest;

	if (!str1 || !str2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!dest)
		return (free(dest), NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		dest[i] = str1[i];
		i++;
	}
	free (str1);
	j = 0;
	while (str2[j] != '\0')
	{
		dest[i] = str2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	size_t		i;
	char		*dest;

	if (!str)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_keep_line(char *str, char *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i] != '\0')
	{
		temp[j] = str[i];
		str[i] = '\0';
		i++;
		j++;
	}
	temp[j] = '\0';
}
