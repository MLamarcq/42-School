/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:06:46 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 16:50:04 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of args !" << std::endl;
		std::cout << "In order to hear Harl complain, please use : ";
		std::cout << "./HarlFilter + one action (DEBUG, INFO, WARNING or ERROR)" << std::endl;
	}
	else
	{
		Harl harl;

		int i;
		std::string level(argv[1]);
		if (level.compare("DEBUG") == 0)
			i = 1;
		else if (level.compare("INFO") == 0)
			i = 2;
		else if (level.compare("WARNING") == 0)
			i = 3;
		else if (level.compare("DEBUG") == 0)
			i = 4;
		else
			i = 0;
		
		switch (i)
		{
			case 1 :
					harl.complain("DEBUG");
					break ;
			case 2 :
					harl.complain("INFO");
					break ;
			case 3 :
					harl.complain("WARNING");
					break ;
			case 4 :
					harl.complain("ERROR");
					break ;
			default :
					std::cout << " [ Probably complaining about insignificant problems ] " << std::endl;
					break ;
		}
	}
	return (0);
}