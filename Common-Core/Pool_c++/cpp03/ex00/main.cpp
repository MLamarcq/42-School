/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 09:57:25 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main()
{
	std::srand(std::time(0));
	ClapTrap robot1("Julien");
	ClapTrap robot2("Thierry");
	ClapTrap robot3("Bernard");

	std::cout << std::endl;
	
	robot1.attack(robot2.getName());
	std::cout << std::endl;
	
	robot2.takeDamage(robot1.getAttackDamage());
	std::cout << std::endl;
	
	robot2.attack(robot1.getName());
	std::cout << std::endl;
	
	robot1.takeDamage(5);
	std::cout << std::endl;
	
	robot3.attack(robot1.getName());

	robot1.takeDamage(5);
	std::cout << std::endl;
	
	robot2.beRepaired(2);
	std::cout << std::endl;
	
	robot2.attack("Bernard");
	std::cout << std::endl;
	
	ClapTrap human4(robot2);
	std::cout << std::endl;
	
	human4.attack(robot1.getName());
	std::cout << std::endl;
	
	return (0);
}