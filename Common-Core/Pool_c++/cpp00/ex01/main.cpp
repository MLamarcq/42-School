/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:36:08 by mael              #+#    #+#             */
/*   Updated: 2023/09/07 15:21:56 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int main(int argc, char **argv)
{
	PhoneBook PhoneBook;
	Contact	Contact;
	if (argc == 1)
	{
		if (PhoneBook.start_phone_book(Contact, PhoneBook) == 0)
			return (0);
	}
	else
	{
		std::cout << "Too much args : ";
		std::cout << "Try ./phonebook to start a new phonebook !" << std::endl;
	}
	return (0);
	(void)argv;
}