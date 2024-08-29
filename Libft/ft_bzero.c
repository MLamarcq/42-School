/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:09:52 by mlamarcq          #+#    #+#             */
/*   Updated: 2022/05/26 11:20:44 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, int len)
{
	unsigned char	*p;
	int				i;

	p = str;
	i = 0;
	while (i < len)
	{
		p[i] = '\0';
		i++;
	}
}

/*
int	main()
{
	char str[] = "Hello";
	
	ft_bzero(str, 2);
	printf("%s\n", str);
	return (0);
}*/
