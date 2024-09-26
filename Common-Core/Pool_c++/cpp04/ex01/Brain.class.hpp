/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:43:44 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 12:20:16 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP

#include "animal.class.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class Brain
{
	
	public :

			Brain(void);
			Brain(std::string name);
			Brain(Brain const &src);
			~Brain(void);

			Brain &operator=(Brain const &rhs);

			std::string	getIdeas(int i) const;
			void		chooseIdea(std::string idea, int nb, int start, int end);
			void		chooseSpecificIdea(void);
			void		printIdea(bool choice, int idea) const;
			void		fillIdea(int index, std::string idea);

	private :

			std::string _ideas[100];
			void		fillBrain(std::string idea);
};

#endif