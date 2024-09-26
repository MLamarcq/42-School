/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:12:50 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 11:35:57 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
#define WRONGANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
		public :

					WrongAnimal(void);
					WrongAnimal(std::string type);
					WrongAnimal(WrongAnimal const &src);
					virtual ~WrongAnimal(void);

					WrongAnimal &operator=(WrongAnimal const &rhs);

					std::string	getType(void) const;
					void		makeSound(void) const;
		
		protected :
		
					std::string _type;
};

#endif