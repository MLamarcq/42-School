#ifndef IMATERIASOURCE_CLASS_HPP
# define IMATERIASOURCE_CLASS_HPP

#include <string>
#include <iostream>
#include "AMateria.class.hpp"

class IMateriaSource
{
	public :
			
			virtual ~IMateriaSource(void){};

			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif