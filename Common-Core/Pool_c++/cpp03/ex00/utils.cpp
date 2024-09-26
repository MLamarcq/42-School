/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:18 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 09:58:26 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int	is_letter(std::string const &str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			i++;
		else
			return (0);
	}
	return (1);
}

std::string	intTostring(int number)
{
	std::string result;
	char digitChar;
	
	while (number <= 0)
	{
		std::srand(0);
		number = std::rand();
	}
	while (number > 0) 
	{
		digitChar = '0' + (number % 10);
		result.push_back(digitChar);
		number /= 10;
	}
	if (result.size() > 4)
		result = result.substr(0, 4);
	return (result);
}