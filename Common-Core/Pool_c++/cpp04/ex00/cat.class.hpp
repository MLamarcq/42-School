/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael <mael@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:16 by mael              #+#    #+#             */
/*   Updated: 2023/10/04 16:04:49 by mael             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "animal.class.hpp"

class Cat : public Animal
{
	public :

			Cat(void);
			Cat(std::string type);
			Cat(Cat const &src);
			virtual ~Cat(void);

			Cat &operator=(Cat const &rhs);
			
			void	makeSound(void) const;
	
};

#endif