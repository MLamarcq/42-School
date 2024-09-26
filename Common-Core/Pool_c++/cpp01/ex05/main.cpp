/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:35:21 by mael              #+#    #+#             */
/*   Updated: 2023/09/13 15:30:53 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of args !" << std::endl;
		std::cout << "In order to hear Harl complain, please use : ";
		std::cout << "./Harl + one action (DEBUG, INFO, WARNING or ERROR)" << std::endl;
	}
	else
	{
		Harl harl;
		std::string level(argv[1]);
		
		harl.complain(level);
	}
	return (0);
}