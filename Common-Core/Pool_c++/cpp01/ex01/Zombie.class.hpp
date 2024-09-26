/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 02:01:41 by mael              #+#    #+#             */
/*   Updated: 2023/09/11 10:05:51 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_CLASS_HPP
#define	ZOMBIE_CLASS_HPP

#include <string>
#include <iostream>

class Zombie
{
	public :
			
			Zombie();
			Zombie(std::string name);
			~Zombie();
			void	announce(int i) const;
			void	setName(Zombie *zombie, int i, std::string name) const;

			
	private :
			
			std::string _name;

};

Zombie	*zombieHorde(int n, std::string name);

#endif