/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:20:32 by mael              #+#    #+#             */
/*   Updated: 2023/10/01 11:50:34 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

class FragTrap : public ClapTrap
{
	public :

			//Constructors / Destructor
			FragTrap(void);
			FragTrap(std::string const name);
			FragTrap(FragTrap const &src);
			~FragTrap(void);
			
			//Assignement operator
			FragTrap &operator=(FragTrap const &rhs);

			//Member fuction
			void	attack(ClapTrap const&target);
			void	higtFiveGuys(ClapTrap const &other);
};