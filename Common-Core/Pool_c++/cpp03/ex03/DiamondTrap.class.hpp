/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:46:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/03 14:36:29 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_CLASS_HPP
#define DIAMONDTRAP_CLASS_HPP

#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public :

			DiamondTrap(void);
			DiamondTrap(std::string name);
			DiamondTrap(DiamondTrap const &src);
			~DiamondTrap(void);

			DiamondTrap &operator=(DiamondTrap const &rhs);
			
			void	attack(std::string const &target);
			void	whoAmI(void);

	private : 

			std::string	_name;
};

#endif