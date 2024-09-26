/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:14:32 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 19:39:56 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.class.hpp"

Harl::Harl()
{
	return ;
}
Harl::~Harl()
{
	return ;
}
void	Harl::complain(std::string level)
{
	std::string comp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	int j = 0;

	while (j < 4)
	{
		if (comp[i].compare(level) != 0)
			i++;
		j++;
	}
	switch (i)
	{
		case 0 :
				_debug();
				_info();
				_warning();
				_error();
				break ;
		case 1 :
				_info();
				_warning();
				_error();
				break ;
		case 2 :
				_warning();
				_error();
				break ;
		case 3 :
				_error();
				break ;
		default :
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break ;
	}
}

void	Harl::_debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !" << std::endl;
	std::cout << "\n";
}

void	Harl::_info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger !" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more !" << std::endl;
	std::cout << "\n";
}

void	Harl::_warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << "\n";
}

void	Harl::_error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	std::cout << "\n";
}