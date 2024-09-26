/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 15:27:08 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "animal.class.hpp"

class Dog : public Animal
{
	public :

			Dog(void);
			Dog(std::string name);
			Dog(Dog const &src);
			virtual ~Dog(void);

			Dog &operator=(Dog const &rhs);

			void		makeSound(void) const;
};


#endif