/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.utils.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:13:06 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 11:58:30 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int	PhoneBook::add_contact(Contact Contact)
{
	int temp;
	
	temp = 0;
	if (_index + 1 > 8)
	{
		temp = _index;
		_index = 0;
	}
	if (Contact.fill_contact(&_contact[_index]) == 0)
		return (0);
	if (temp)
		_index = temp;
	else
		_index++;
	if (_nbr_contact < 8)
		_nbr_contact++;
	return (1);
}

int	PhoneBook::nb_contact() const
{
	return (_nbr_contact);
}

void	PhoneBook::display_all(Contact Contact) const
{
	int i;
	
	i = 0;
	std::cout << std::internal << std::setw(11) << "Index |" ;
	std::cout << std::internal << std::setw(11) << "FirstName |" ;
	std::cout << std::internal << std::setw(11) << "LastName |" ;
	std::cout << std::internal << std::setw(11) << "NickName |" << std::endl;
	while (i < _index)
	{
		_contact[i].print_inside_contact(i);
		std::cout << "\n";
		i++;
	}
	(void)Contact;
}

void	PhoneBook::display_contact(int index) const
{
	_contact[index - 1].print_contact(index);
}