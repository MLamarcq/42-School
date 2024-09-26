/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:45:35 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 10:50:51 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	// std::string name;
	// bool		toggle;
	
	// toggle = false;
	// std::cout << "A new FragTrap is now created !" << std::endl;
	// std::cout << "Let's give him a name ! Enter your name :";
	
	// while (toggle == false)
	// {
	// 	if (!(std::getline(std::cin, name)))
	// 	{
	// 		std::cout << "Getline problem" << std::endl;
	// 		return ;
	// 	}
	// 	else
	// 		toggle = true;
	// }
	this->_name = "FragTrap";
	this->_HitPoints = 100;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	std::cout << this->_name << " is now alive !" << "\n" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
	std::string convert;
	int			personalNumber;
	
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (src._isDead == true)
	{
		std::cout << src._name << " is dead. How cam he be cloned?" << std::endl;
		std::cout << "You should probably repair him !" << std::endl;
		return ;
	}
	personalNumber = std::rand();
	convert = intTostring(personalNumber);
	*this = src;
	this->_name.append("#");
	this->_name.append(convert);
	std::cout << "Welcome to " << this->_name << " a clone of " << src._name << "\n" << std::endl;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_HitPoints = rhs._HitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_AttackDamage = rhs._AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void	FragTrap::attack(ClapTrap const &target)
{
	if (target.getDeath() == true)
	{
		std::cout << this->_name << " is trying to attack " << target.getName() << std::endl;
		std::cout << "But " << target.getName() << " is dead" << std::endl;
		std::cout << "Will you hit a dead man ? Poor you...\n" << std::endl;
		return ;
	}
	if (this->_isDead == true)
	{
		std::cout << "Your FragTrap " << this->_name << " is dead ! How could he attack ?" << std::endl;
		std::cout << "Let him rest in peace !" << std::endl;
		return ;
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energie Point left. No attack possble" << std::endl;
		return ;
	}
	if (this->_AttackDamage == 0)
	{
		std::cout << this->_name << " attacked " << target.getName() << " but did " << this->_AttackDamage << " unlucky." << std::endl;
		std::cout << "Come on, give him a chance to it, it's a FragTrap after all !" << std::endl;
		std::cout << "Choose a number, it will be " << this->_name << " new attack domage (you can refuse, a 'No' is enought) :";
		while (this->_AttackDamage == 0)
		{
			std::string input;
			int			newAttackDamage;
			
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "Getline error" << std::endl;
				return ;
			}
			if (input.compare("No") == 0)
			{
				std::cout << "Okay... i do not insist..." << std::endl;
				return ;
			}
			newAttackDamage = std::atoi(input.c_str());
			if (newAttackDamage == 0)
			{
				std::cout << "Come on ! You are cruel !" << std::endl;
				std::cout << "I let you another chance :";
			}
			else
				this->_AttackDamage = newAttackDamage;
		}
	}
	this->_EnergyPoints--;
	std::cout << "FragTrap " << this->_name << " attacked " << target.getName() << " causing " << this->_AttackDamage << " points of damage" << std::endl;
	return ;
}

void	FragTrap::higtFiveGuys(ClapTrap const &other)
{
	if (this->_isDead == true)
	{
		std::string input;
		bool		toggle = false;
		bool		check = false;
		int			new_hitpoint;
		
		std::cout << "Unfortunatly, " << this->_name << " is dead. Hight five are not possible" << std::endl;
		std::cout << "A repair could be the solution. Want you to repair " << this->_name << " ? ";
		std::cout << "Type your answer ('Yes' or 'No' ): ";
		while (toggle == false)
		{
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "Getline issue" << std::endl;
				return ;
			}
			if (input.compare("Yes") == 0)
			{
				if (this->_EnergyPoints == 0)
				{
					std::cout << "No energy point left, can't repair." << std::endl;
					return ;
				}
				std::cout << "Alright ! Let's repair him ! ";
				std::cout << "Type a number : ";
				while (check == false)
				{
					if (!(std::getline(std::cin, input)))
					{
						std::cout << "Getline problem" << std::endl;
						return ;
					}
					if (is_digit(input) == 0)
						std::cout << "Wrong input. Must be a number. Try again : ";
					else
						check = true;
				}
			 	new_hitpoint = std::atoi(input.c_str());
				this->_HitPoints = this->_HitPoints + new_hitpoint;
				this->_isDead = false;
				std::cout << "\n" << this->_name << " is now repaired ! He has now " << this->_HitPoints << " hit points ! Thanks for him" << std::endl;
				this->_EnergyPoints--;
				toggle = true;
			}
			else if (input.compare("No") == 0)
			{
				std::cout << "Okay, no problem. I hope you feel guilty. No higt five possible\n" << std::endl;
				toggle = true;
				return ;
			}
			else
				std::cout << "Wrong input, please try again : ";
		}
	}
	std::cout << this->_name << " is doing a high five to " << other.getName() << "\n" << std::endl;
	return ;
}
