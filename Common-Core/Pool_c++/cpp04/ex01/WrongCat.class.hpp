/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:18:09 by mael              #+#    #+#             */
/*   Updated: 2023/10/05 11:32:02 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
#define WRONGCAT_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
	
	public :

			WrongCat(void);
			WrongCat(std::string type);
			WrongCat(WrongCat const &src);
			~WrongCat(void);

			WrongCat &operator=(WrongCat const &rhs);

			void	makeSound(void) const;
};

#endif