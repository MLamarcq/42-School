/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:16 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 13:18:37 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "animal.class.hpp"
#include "Brain.class.hpp"

class Cat : public Animal
{
	public :

			Cat(void);
			Cat(std::string type);
			Cat(Cat const &src);
			virtual ~Cat(void);

			Cat &operator=(Cat const &rhs);
			
			void		makeSound(void) const;
			Brain		*getBrain(void) const;
			std::string	GetIdeas(int idea) const;
			void		PrintIdea(bool choice, int idea) const;
			void		ChooseIdea(std::string idea, int target, int start, int end);
			void		ChooseSpecificIdea(void);

	private :

			Brain	*_brain;
};

#endif