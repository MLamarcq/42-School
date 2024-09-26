/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:06:44 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 17:57:38 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"

int	is_correct(std::string str)
{
	int i = 0;
	
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= '0' && str[i] <= '9') || str[i] == 32 || str[i] == 39)
			i++;
		else
			return (0);
	}
	return (1);
}
		
		
int is_digit(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}