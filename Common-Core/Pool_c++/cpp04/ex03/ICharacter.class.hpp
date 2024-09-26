#ifndef ICHARACTER_CLASS_HPP
#define ICHARACTER_CLASS_HPP

#include "AMateria.class.hpp"
#include <string>
#include <iostream>

class AMateria;

class ICharacter
{
	public :

			virtual ~ICharacter(void){};

			//ICharacter &operator=(ICharacter const &rhs) = 0;

			virtual std::string const	&getName() const = 0;
			virtual void				equip(AMateria *materia) = 0;
			virtual void				use(int index, ICharacter &target) = 0;
			virtual AMateria			*getItem(int index) const = 0;
			virtual void				unEquip(int index) = 0;
			virtual	void				on_the_floor(void) const = 0;

};

#endif