/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:20:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 11:16:29 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap(void) : _name(ClapTrap::_name)
{
	std::cout << "DiamondTrap default constructor called\n" << std::endl;
	std::cout << "Say welcome to " << this->_name << std::endl;
	ClapTrap::_name = ClapTrap::_name + "_clap_trap";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	std::cout << "DiamondTrap name assignement constructor called\n" << std::endl;
	std::cout << "Say welcome to " << this->_name << std::endl;
	ClapTrap::_name = _name + "_clap_trap";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_EnergyPoints = ScavTrap::_EnergyPoints;
	this->_AttackDamage = FragTrap::_AttackDamage;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap (src), ScavTrap(src),  FragTrap(src)
{
	std::string	convert;
	int			personalNumber;
	
	std::cout << "DiamondTrap copy constructor called\n" << std::endl;
	if (this->_isDead == true)
	{
		std::cout << this->_name << " is dead. No cloning possible. Try a repair !" << std::endl;
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

DiamondTrap & DiamondTrap::operator=(DiamondTrap const &rhs)
{
	std::cout << "DiamondTrap copy operator called\n" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_HitPoints = rhs.getHitpoints();
		this->_EnergyPoints = rhs.getEnergyPoints();
		this->_AttackDamage = rhs.getAttackDamage();
		this->_isDead = rhs.getDeath();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::whoAmI()
{
	if (this->_isDead == true)
	{
		std::string input;
		bool		toggle = false;
		
		std::cout << this->_name << " is dead ! (Oh no !)" << std::endl;
		std::cout << "But, there is a way. We may repair him !" << std::endl;
		std::cout << "Type an action : 'Repair' or 'No repair' : ";
		
		while(toggle == false)
		{
			if (!(std::getline(std::cin, input)))
			{
				std::cout << "EOF called" << std::endl;
				return ;
			}
			if (input.compare("Repair") == 0)
			{
				std::string input2;
				bool		check = false;
				int			amout = 0;
				
				std::cout << "Oh yeah, let's repair !" << std::endl;
				std::cout << "Type the amout of hit points you want to give to " << this->_name << " : ";
				while (check == false)
				{
					if (!(std::getline(std::cin, input2)))
					{
						std::cout << "Getline issue" << std::endl;
						return ;
					}
					if (is_digit(input2) == 0)
						std::cout << "Wrong input. Try again : ";
					else
					{
						amout = amout + std::atoi(input2.c_str());
						this->_HitPoints = this->_HitPoints + amout;
						std::cout << this->_name << " reborns with an amout of " << this->_HitPoints << " hit points !" << std::endl;
						this->_isDead = false;
						this->_EnergyPoints--;
						check = true;
						toggle = true;
					}
				}
			}
			else if (input.compare("No repair") == 0)
			{
				std::cout << "Alright, " << this->_name << " still dead. He can't present himself" << std::endl;
				toggle = true;
				return ;
			}
			else
				std::cout << "Wrong input. Please, try again : ";
		}
	}
	std::cout << "Hey, I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "\n" << std::endl;
	return ;
}