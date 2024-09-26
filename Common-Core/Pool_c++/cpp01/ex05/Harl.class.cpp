/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:48 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 15:57:35 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

Harl::Harl()
{
	// std::cout << "Harl constructed" << std::endl;
	return ;
}
Harl::~Harl()
{
	// std::cout << "Harl destructed" << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{

	int i = 0;
	std::string	complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::_error(void) const
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}