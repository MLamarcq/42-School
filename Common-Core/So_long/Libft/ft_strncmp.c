/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:27:29 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/20 11:05:33 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && (s1[i] == s2[i]) && i < (n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <string.h>

	char	s1[] = {"BONJOUr"};
	char	s2[] = {"BONJOUR"};

	ft_strncmp(s1, s2, 10);
	printf("%d\n", ft_strncmp(s1, s2, 0));
	printf("%d\n", strncmp(s1, s2, 0));
	return (0);
}*/
