/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 15:27:01 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class Animal
{
	public :

			Animal(void);
			Animal(std::string name);
			Animal(Animal const &src);
			virtual ~Animal(void);

			Animal &operator=(Animal const &rhs);

			virtual std::string	getType(void) const;
			virtual void		makeSound(void) const;


	protected :

				std::string	_type;

};

#endif