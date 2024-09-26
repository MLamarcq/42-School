/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 10:45:59 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"


int main()
{
	std::srand(std::time(0));
	ScavTrap robot1("Francis");
	ScavTrap robot2(robot1);
	ScavTrap robot3(robot1);
	ClapTrap robot4;
	std::cout << std::endl;

	
	std::cout << "Here are our Gate Keepers !" << std::endl << std::endl;
	robot1.guardGate();
	robot2.guardGate();
	robot3.guardGate();

/*************************************************************************/

	// robot1.attack(robot4.getName());
	// robot4.takeDamage(robot1.getAttackDamage());
	// robot4.attack(robot1.getName());

	// std::cout << "Let's do some domages !" << std::endl;
	// robot1.attack(robot2.getName());
	// robot2.takeDamage(robot1.getAttackDamage());
	// robot2.attack(robot1.getName());
	// robot1.takeDamage(robot2.getAttackDamage());
	// robot3.attack(robot2.getName());
	// robot2.takeDamage(robot3.getAttackDamage());
	// std::cout << "We need some repair after huge fight !" << std::endl;
	// robot1.beRepaired(52);
	// robot2.beRepaired(3);
	// std::cout << std::endl;


/*************************************************************************/
	
	// std::cout << "Let's have more blood (euh, oil in fact)" << std::endl;
	// while (robot2.getEnergyPoints() > 0 && robot1.getDeath() == false)
	// {
	// 	robot2.attack(robot1.getName());
	// 	robot1.takeDamage(robot2.getAttackDamage());
	// }
	// std::cout << "Can " << robot2.getName() << " attack once more?" << std::endl;
	// std::cout << robot2.getName() << " has " << robot2.getEnergyPoints() << " energy points left." << std::endl;
	// if (robot2.getEnergyPoints() > 0)
	// {
	// 	std::cout << "Of course he can !" << std::endl;
	// 	robot2.attack(robot3.getName());
	// 	robot3.takeDamage(robot2.getAttackDamage());
	// }
	// else
	// 	std::cout << "Unlucky no energy points left !" << std::endl;
	
	
/*************************************************************************/

	
	// std::cout << "\nNow to the death !" << std::endl;
	// while (robot3.getHitpoints() > 0 && robot3.getDeath() == false)
	// {
	// 	robot1.attack(robot3.getName());
	// 	robot3.takeDamage(robot1.getAttackDamage());
	// }
	// std::cout << "\nOh no, he is dead ! Let's repair him !" << std::endl;
	// robot3.beRepaired(60);
	// std::cout << robot3.getName() << " feels better !\n" << std::endl;
	
	return (0);
}