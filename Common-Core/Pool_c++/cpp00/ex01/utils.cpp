/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:33:07 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 10:28:03 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int	is_digit(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_letter(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strncmp(std::string str, std::string dest, int n)
{
	int i;

	i = 0;
	while (str[i] && dest[i] && (str[i] == dest[i]) && i < n)
		i++;
	return (str[i] - dest[i]);
}

int	ft_strlen(std::string str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_char(std::string str, int n)
{
	if (n == '1')
	{
		if (is_digit(str) == 0)
			return (0);
	}
	else if (n == '2')
	{
		if (is_letter(str) == 0)
			return (0);
	}
	return (1);
}