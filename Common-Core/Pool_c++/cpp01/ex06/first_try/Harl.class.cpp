/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:31:41 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 16:54:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

Harl::Harl(void)
{
	return ;
}
Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	std::string complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*comp[4])(void) const;
	
	comp[0] = &Harl::_debug;
	comp[1] = &Harl::_info;
	comp[2] = &Harl::_warning;
	comp[3] = &Harl::_error;

	while (i < 4)
	{
		if (complain[i].compare(level) == 0)
			(this->*comp[i])();
		i++;
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