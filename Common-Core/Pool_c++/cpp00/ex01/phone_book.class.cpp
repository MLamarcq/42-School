/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:32:58 by mael              #+#    #+#             */
/*   Updated: 2023/10/08 15:33:31 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

PhoneBook::PhoneBook(void) : _index(0) , _nbr_contact(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::start_phone_book(Contact Contact, PhoneBook PhoneBook)
{
	std::string input;
	
	std::cout << "Welcome to your new phonebook !" << std::endl;
	std::cout << "Type 'Yes' to start or 'Exit' to quit : ";
	if (!(std::getline(std::cin, input)))
			return (0);
	if (ft_strncmp(input, "Exit", ft_strlen(input)) == 0)
		return (0);
	while (ft_strncmp(input, "Yes", ft_strlen(input)) != 0 && \
		ft_strncmp(input, "Exit", ft_strlen(input)) != 0)
	{
		std::cout << "Wrong input. Please try again : ";
		std::getline(std::cin, input);
	}
	if (ft_strncmp(input, "Exit", ft_strlen(input)) == 0)
		return (0);
	std::cout << "\n\n";
	std::cout << "Only 3 action allowed : ADD, SEARCH and EXIT" << std::endl;
	std::cout << "Chosse ADD to create a new contact, ";
	std::cout << "Search to see all your contact, ";
	std::cout << "and EXIT to quit your phonebook !" << std::endl;
	while (1)
	{
		input.erase();
		std::cout << "\n";
		std::cout << "Please, enter your action (ADD, SEARCH, EXIT): ";
		if (!(std::getline(std::cin, input)))
			return (0);
		if (ft_strncmp(input, "ADD", ft_strlen(input)) == 0)
		{
			std::cout << "\n";
			if (PhoneBook.nb_contact() == 8)
			{
				std::cout << "You are trying to set a 9th contact. ";
				std::cout << "In that case the oldest will be replace by the new one. The oldest will be lost.";
				std::cout << "\nType 'Yes' to continue or 'Exit' to go back to the main menu : ";
				if (!(std::getline(std::cin, input)))
					return (0);
				while (ft_strncmp(input, "Yes", ft_strlen(input)) != 0 && \
					ft_strncmp(input, "Exit", ft_strlen(input))!= 0)
				{
					std::cout << "Wrong input. Please try again : ";
					std::getline(std::cin, input);
				}
				if (ft_strncmp(input, "Exit", ft_strlen(input)) == 0)
					std::cout << "\nNo changes. Back to the main menu." << std::endl;
				else
				{
					if (PhoneBook.add_contact(Contact) == 0)
						return (0);
				}
				//system("clear");
			}
			else
			{
				if (PhoneBook.add_contact(Contact) == 0)
					return (0);
				//system("clear");
			}
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "\n";
			if (PhoneBook.nb_contact() == 0)
			{
				std::cout << "No contact set yet. Please type 'ADD' to start your phonebook" << std::endl;
			}
			else
			{
				PhoneBook.display_all(Contact);
				std::cout << "\n";
				std::cout << "You will be able to see all ";
				std::cout << "about the contact you choose" << std::endl;
				std::cout << "Please enter an index between 1 and 8 : ";
				if (!(std::getline(std::cin, input)))
					return (0);
				while (is_digit(input) == 0 || ft_strlen(input) != 1)
				{
					std::cout << "Please enter a number between 1 and 8 : ";
					if (!(std::getline(std::cin, input)))
						return (0);
				}
				while (std::atoi(input.c_str()) < 1 || std::atoi(input.c_str()) > 8)
				{
					std::cout << "Wrong input. ";
					std::cout << "Please enter a number between 1 and 8 : ";
					if (!(std::getline(std::cin, input)))
						return (0);
				}
				while (std::atoi(input.c_str()) > PhoneBook.nb_contact())
				{
					std::cout << "This contact does not exit. ";
					std::cout << "Please try one who's already set : ";
					if (!(std::getline(std::cin, input)))
						return (0);
				}
				PhoneBook.display_contact(std::atoi(input.c_str()));
			}

		}
		else if (ft_strncmp(input, "EXIT", ft_strlen(input)) == 0)
			break ;
		else
			std::cout << "Wrong input, please try again" << std::endl;
	}
	return (1);
}
