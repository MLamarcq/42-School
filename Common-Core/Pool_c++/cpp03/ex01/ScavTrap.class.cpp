/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:21:54 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 10:14:37 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Name ScavTrap constructor called" << std::endl;
	std::cout << this->_name << " is now alive !\n" << std::endl;
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	int personalNumber;
	std::string convert;
	
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	if (src._HitPoints <= 0)
	{
		std::cout << "ScavTrap " << src._name << " is dead. How can he be cloned ?\n" << std::endl;
		return ;
	}
	personalNumber = std::rand();
	convert = intTostring(personalNumber);
	*this = src;
	this->_name.append("#");
	this->_name.append(convert);
	std::cout << "Here is " << this->_name << ", a clone of ScavTrap " << src._name << "\n" << std::endl;	
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "Copy ScavTrap operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_isDead == true)
	{
		std::cout << "ScavTrap " << this->_name << " is destructed. How can he attacks?\n" << std::endl;
		return ;
	}
	if (target.size() == 0)
	{
		std::cout << "ScavTrap needs a name to attack !" << std::endl;
		return ;
	}
	if (this->_AttackDamage <= 0)
	{
		std::cout << "With " << this->_AttackDamage << " your ScavTrap attack is useless. Unlucky\n" << std::endl;
		return ;
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energy point left. No action possbile\n" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage\n" << std::endl;
	this->_EnergyPoints--;
}
void	ScavTrap::guardGate(void)
{
	if (this->_HitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " is dead. No Gate Keeper mode possible\n" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode\n" << std::endl;
}

