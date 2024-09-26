/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:16 by mael              #+#    #+#             */
/*   Updated: 2023/10/17 19:17:46 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "animal.class.hpp"
#include "Brain.class.hpp"

class Cat : public Aanimal
{
	public :

			Cat(void);
			Cat(std::string type);
			Cat(Cat const &src);
			virtual ~Cat(void);

			Cat &operator=(Cat const &rhs);
			
			void		makeSound(void) const;
			std::string	GetIdeas(int idea) const;
			void		FillBrain(std::string idea);
			void		PrintIdea(bool choice, int idea) const;
			void		ChooseIdea(std::string idea, int target, int start, int end);
			void		ChooseSpecificIdea(void);
			Brain		*getBrain(void) const;

	private :

			Brain	*_brain;
};

#endif