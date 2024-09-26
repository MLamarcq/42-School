/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:50:27 by mael              #+#    #+#             */
/*   Updated: 2023/09/27 14:29:34 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"


class ScavTrap : public ClapTrap
{
	public :
				ScavTrap(void);
				ScavTrap(std::string name);
				ScavTrap(ScavTrap const &src);
				~ScavTrap(void);

				ScavTrap & operator=(ScavTrap const &rhs);

				void	attack(std::string const &target);
				void	guardGate(void);
};

#endif