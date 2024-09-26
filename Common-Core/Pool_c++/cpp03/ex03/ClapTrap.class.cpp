/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:14:46 by mael              #+#    #+#             */
/*   Updated: 2023/10/16 11:05:47 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void) : _HitPoints(10), _EnergyPoints(2), _AttackDamage(0), _isDead(false)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "ClapTrap";
	return;
}
ClapTrap::ClapTrap(std::string const name) : _name(name), _HitPoints(10), _EnergyPoints(2), _AttackDamage(0), _isDead(false)
{
	std::cout << "ClapTrap setting name constructor called" << std::endl;
	return ;
}
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
	std::cout << "ClapTrap destructor called\n" << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_isDead == true)
	{
		std::cout << "ClapTrap "<< this->_name << " is dead. How can he attacks?\n" << std::endl;
		return ;
	}
	if (this->_name.size() == 0)
	{
		std::string name;
		std::cout << "Your ClapTrap has no name !" << std::endl;
		std::cout << "Let's give him a sweet name. In that case, an attack could be possible !" << std::endl;
		std::cout << "Please, write his name : ";
		if (!std::getline(std::cin, name))
			return ;
		else
			this->_name = name;
		std::cout << "Say welcome to our new ClapTrap : " << this->_name << std::endl;
	}
	if (target.size() == 0)
	{
		std::cout << "Please set a target, it can't be nothing !\n" << std::cout;
		return ;
	}
	if (this->_AttackDamage <= 0)
	{
		std::cout << "With " << this->_AttackDamage << " attack point " <<  this->_name << " attacks is useless. Unlucky\n" << std::endl;
		return ;
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energy point left. No action possbile\n" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage\n" << std::endl;
	this->_EnergyPoints--;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_name.size() == 0)
	{
		std::string name;
		std::cout << "Your ClapTrap has no name !" << std::endl;
		std::cout << "Let's give him a sweet name. In that case, an repair could be possible !" << std::endl;
		std::cout << "Please, write his name : ";
		if (!std::getline(std::cin, name))
			return ;
		else
			this->_name = name;
		std::cout << "Say welcome to our new ClapTrap : " << this->_name << std::endl;
	}
	if (this->_EnergyPoints == 0)
	{
		std::cout << "No Energy point left. No action possbile\n" << std::endl;
		return ;
	}
	if (this->_HitPoints == 0)
	{
		std::cout << this->_name << " is dead. Let's him come back !" << std::endl;
		this->_HitPoints = this->_HitPoints + amout;
		std::cout << this->_name << " is getting repair with an amout of " << amout << " hit points" << std::endl;
		std::cout << this->_name << " has now " << this->_HitPoints << " hit points\n" << std::endl;
		this->_EnergyPoints--;
		return ;
	}
	this->_HitPoints = this->_HitPoints + amout;
	std::cout << this->_name << " is getting repair with an amout of " << amout << " hit points" << std::endl;
	std::cout << this->_name << " has now " << this->_HitPoints << " hit points\n" << std::endl;
	this->_EnergyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (this->_name.size() == 0)
	{
		std::string name;
		std::cout << "Your ClapTrap has no name !" << std::endl;
		std::cout << "Let's give him a sweet name. In that case, take damage could be possible !" << std::endl;
		std::cout << "Please, write his name : ";
		if (!std::getline(std::cin, name))
			return ;
		else
			this->_name = name;
		std::cout << "Say welcome to our new ClapTrap : " << this->_name << std::endl;
	}
	if (amout > this->_HitPoints)
	{
		this->_HitPoints = 0;
		std::cout << this->_HitPoints << " hit points still remain for " << this->_name << "\n" << std::endl;
		std::cout << this->_name << " died. RIP\n" << std::endl;
		this->_isDead = true;
		return ;
	}
	else
		this->_HitPoints = this->_HitPoints - amout;
	std::cout << this->_name << " takes damages, an amout of " << amout << " damages points" << std::endl;
	std::cout << this->_HitPoints << " hit points still remain for " << this->_name << "\n" << std::endl;
	return ;
}

unsigned int ClapTrap::getHitpoints(void) const
{
	return (this->_HitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_EnergyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_AttackDamage);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

bool ClapTrap::getDeath(void) const
{
	return (this->_isDead);
}
