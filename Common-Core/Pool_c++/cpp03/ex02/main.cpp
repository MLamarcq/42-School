/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:29:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 10:58:55 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"



int main()
{
	std::srand(std::time(0));
	
	//basic test
	FragTrap robot1("Michel");
	FragTrap robot2("Didier");
	ScavTrap robot3("Francis");
	FragTrap robot4 (robot1);
	
	robot1.attack(robot2);
	robot2.takeDamage(robot1.getAttackDamage());
	robot2.attack(robot3);
	robot3.takeDamage(robot2.getAttackDamage());
	while (robot2.getDeath() == false)
	{
		robot3.attack("Didier");
		robot2.takeDamage(robot3.getAttackDamage());
	}
	robot1.attack(robot2);
	robot2.higtFiveGuys(robot1);
	
	
	

	
	return (0);
}