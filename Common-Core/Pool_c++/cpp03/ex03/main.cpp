/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 11:11:02 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"


int main()
{
	std::srand(std::time(0));
	
	DiamondTrap robot1("Didier");
	FragTrap	robot2("Julien");
	
	
	// robot1.whoAmI();
	// robot1.attack("Julien");
	// robot2.takeDamage(robot1.getAttackDamage());
	// robot1.higtFiveGuys(robot2);
	

/*************************************************************************/

	while(robot1.getDeath() == false && robot2.getEnergyPoints() > 0)
	{
		robot2.attack(robot1.getName());
		robot1.takeDamage(robot2.getAttackDamage());
	}
	robot1.whoAmI();
	
	return (0);
}