/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/27 13:56:20 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <string>
#include <iostream>

class Aanimal
{
	public :

			Aanimal(void);
			Aanimal(std::string name);
			Aanimal(Aanimal const &src);
			virtual ~Aanimal(void);

			Aanimal &operator=(Aanimal const &rhs);

			std::string			getType(void) const;
			virtual void		makeSound(void) const = 0;
			virtual void		PrintIdea(bool choice, int idea) const = 0;
			virtual void		ChooseIdea(std::string idea, int target, int start, int end) = 0;
			virtual void		ChooseSpecificIdea(void) = 0;

	protected :

				std::string	_type;

};

int	is_correct(std::string str);
int is_digit(std::string str);

#endif