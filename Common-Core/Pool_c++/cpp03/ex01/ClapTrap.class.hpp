/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:06:45 by mael              #+#    #+#             */
/*   Updated: 2023/09/27 14:37:09 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class ClapTrap
{
	public : 

			//Constructors / Destructor
			ClapTrap();
			ClapTrap(std::string const name);
			ClapTrap(ClapTrap const &src);
			~ClapTrap();

			//Operators
			ClapTrap & operator=(ClapTrap const &rhs);


			//Function member
			void			attack(std::string const &target);
			void			takeDamage(unsigned int amount);
			void			beRepaired(unsigned int amout);
			unsigned int	getHitpoints(void) const;
			unsigned int	getEnergyPoints(void) const;
			unsigned int	getAttackDamage(void) const;
			std::string		getName(void) const;
			bool			getDeath(void) const;


	protected:

			std::string				_name;
			unsigned int			_HitPoints;
			unsigned int			_EnergyPoints;
			unsigned int			_AttackDamage;
			bool					_isDead;
};

int	is_correct(std::string const	&str);
std::string	intTostring(int number);



#endif