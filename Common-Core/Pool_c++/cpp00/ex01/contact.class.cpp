/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:01:45 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 15:26:12 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include <iostream>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int Contact::fill_names(Contact *Contact, std::string str, int i)
{
	while(str.size() < 1)
	{
		if (!(std::getline(std::cin, str)))
		{
			std::cout << "std::getline failed" << std::endl;
			return (0);
		}
	}
	while (check_char(str, '2') == 0)
	{
		std::cout << "Only letters are accepted. Try again : ";
		if (!(std::getline(std::cin, str)))
		{
			std::cout << "std::getline failed" << std::endl;
			return (0);
		}
	}
	if (i == 0)
		Contact->_FirstName = str;
	else if (i == 1)
		Contact->_LastName = str;
	else if (i == 2)
		Contact->_NickName = str;
	else if (i == 4)
		Contact->_DarkestSecret = str;
	return (1);
}

int Contact::fill_phone_number(Contact *Contact, std::string str, int i)
{
	while(ft_strlen(str) < 1)
	{
		if (!(std::getline(std::cin, str)))
		{
			std::cout << "std::getline failed" << std::endl;
			return (0);
		}
	}
	while (check_char(str, '1') == 0)
	{
		std::cout << "Only digit are accepted. Try again : ";
		if (!(std::getline(std::cin, str)))
		{
			std::cout << "std::getline failed" << std::endl;
			return (0);
		}
	}
	if (i == 3)
		Contact->_PhoneNumber = str;
	return (1);
}

int	Contact::fill_contact(Contact *Contact)
{
	int i;
	std::string str;

	i = 0;
	while (i < 5)
	{
		str.erase();
		if (i == 0)
		{
			std::cout << "Choose first name for this contact : ";
			if (fill_names(Contact, str, i) == 0)
				return (0);
		}
		else if (i == 1)
		{
			std::cout << "Choose last name for this contact : ";
			if (fill_names(Contact, str, i) == 0)
				return (0);
		}
		else if (i == 2)
		{
			std::cout << "Choose nick name for this contact : ";
			if (fill_names(Contact, str, i) == 0)
				return (0);
		}
		else if (i == 3)
		{
			std::cout << "Choose phone number for this contact : ";
			if (fill_phone_number(Contact, str, i) == 0)
				return (0);
		}
		else if (i == 4)
		{
			std::cout << "Choose darkest secret for this contact : ";
			if (fill_names(Contact, str, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
