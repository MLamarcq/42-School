/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:14:46 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 10:49:19 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "ClapTrap";
	return;
}
ClapTrap::ClapTrap(std::string const name) : _name(name), _HitPoints(10), _EnergyPoints(2), _AttackDamage(5)
{
	std::cout << "Setting name constructor called" << std::endl;
	std::cout << "Say welcome to our new ClapTrap : " << this->_name << std::endl;
	std::cout << std::endl;
	return ;
}
// ClapTrap::ClapTrap(ClapTrap const & src)
// {
// 	std::cout << "Copy constructor called" << std::endl;
// 	if (src._HitPoints <= 0)
// 	{
// 		std::cout << "ClapTrap " << src._name << " died. How can he be cloned ?" << std::endl;
// 		return ;
// 	}
// 	*this = src;
// 	this->_name.append("2");
// 	std::cout << "Here is " << this->_name << ", a clone of ClapTrap " << src._name << std::endl;
// 	(void)src;
// 	return ;
// }

ClapTrap::ClapTrap(ClapTrap const & src)
{
	int personalNumber;
	std::string convert;
	
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	if (src._HitPoints <= 0)
	{
		std::cout << "ClapTrap " << src._name << " is dead. How can he be cloned ?\n" << std::endl;
		return ;
	}
	personalNumber = std::rand();
	convert = intTostring(personalNumber);
	*this = src;
	this->_name.append("#");
	this->_name.append(convert);
	std::cout << "Here is " << this->_name << ", a clone of ClapTrap " << src._name << std::endl;	
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_AttackDamage = rhs._AttackDamage;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_HitPoints = rhs._HitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_AttackDamage);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_HitPoints);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_name.size() == 0)
	{
		return ;
	}
	if (target.size() == 0)
	{
		std::cout << "Please set a target, it can't be" << std::cout;
		return ;
	}
	// if (is_correct(target) == 0)
	// {
	// 	std::cout << "Wrong name\n" << std::endl;
	// 	return ;
	// }
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energy point left. No action possbile. " << this->_name  << " can not attack !" << std::endl;
		return ;
	}
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap "<< this->_name << " is dead. How can he attacks?" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage" << std::endl;
	this->_EnergyPoints--;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_name.size() == 0)
	{
		return ;
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energy point left. No action possbile" << std::endl;
		return ;
	}
	if (this->_HitPoints <= 0)
	{
		std::cout << "ClapTrap "<< this->_name << " is dead. How can he be repaired?" << std::endl;
		return ;
	}
	this->_HitPoints = this->_HitPoints + amout;
	std::cout << "ClapTrap " << this->_name << " is getting repair with an amout of " << amout << " hit points" << std::endl;
	std::cout << this->_name << " has now " << this->_HitPoints << " hit points" << std::endl;
	this->_EnergyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (this->_name.size() == 0)
	{
		return ;
	}
	if (this->_HitPoints - amout <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " died. RIP" << std::endl;
		this->_HitPoints = this->_HitPoints - amout;
		return ;
	}
	this->_HitPoints = this->_HitPoints - amout;
	std::cout << "ClapTrap " << this->_name << " takes damages, an amout of " << amout << " damages points" << std::endl;
	std::cout << this->_HitPoints << " hit points still remain for " << this->_name << std::endl;
	return ;
}

