/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:10:39 by mael              #+#    #+#             */
/*   Updated: 2023/09/08 11:58:44 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

void	Contact::print_contact(int i) const
{
	std::cout << "\n\tYou selected contact : " << i << std::endl;
	std::cout << "\nFirst name : " << _FirstName << std::endl;
	std::cout << "Last name : " << _LastName << std::endl; 
	std::cout << "Nick name : " << _NickName << std::endl; 
	std::cout << "Phone Number : " << _PhoneNumber << std::endl; 
	std::cout << "Darkest Secret : " << _DarkestSecret << std::endl;
	std::cout << "\n";
}

void	Contact::print_inside_contact(int i) const
{
	std::cout << std::right << std::setw(10) << (i + 1) << "|";
	if (ft_strlen(_FirstName) > 10)
		std::cout << std::right << std::setw(9) << _FirstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _FirstName << "|";
	if (ft_strlen(_LastName) > 10)
		std::cout << std::right << std::setw(9) << _LastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _LastName << "|";
	if (ft_strlen(_NickName) > 10)
		std::cout << std::right << std::setw(9) << _NickName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << _NickName << "|";
}