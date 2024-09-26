/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 13:51:13 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>
#include "Brain.class.hpp"

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
			virtual void		PrintIdea(bool choice, int idea) const;
			virtual void		ChooseIdea(std::string idea, int target, int start, int end);
			virtual void		ChooseSpecificIdea(void);


	protected :

				std::string	_type;

};

int	is_correct(std::string str);
int is_digit(std::string str);

#endif