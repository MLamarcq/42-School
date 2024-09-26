/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:14 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 12:28:04 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "animal.class.hpp"
#include "Brain.class.hpp"

class Dog : public Animal
{
	public :

			Dog(void);
			Dog(std::string name);
			Dog(Dog const &src);
			virtual ~Dog(void);

			Dog &operator=(Dog const &rhs);

			void		makeSound(void) const;
			Brain		*getBrain(void) const;
			std::string	GetIdeas(int idea) const;
			void		PrintIdea(bool choice,int idea) const;
			void		ChooseIdea(std::string idea, int target, int start, int end);
			void		ChooseSpecificIdea(void);

	private :
	
			Brain	*_brain;
};


#endif