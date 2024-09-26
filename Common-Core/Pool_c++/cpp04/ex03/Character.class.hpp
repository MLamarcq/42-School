#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"

class Character : public ICharacter
{
	public :
		
		Character(void);
		Character(std::string name);
		Character(Character const &src);
		~Character(void);

		Character &operator=(Character const &rhs);

		std::string const	&getName() const;
		void				equip(AMateria *materia);
		void				use(int index, ICharacter &target);
		AMateria			*getItem(int index) const;
		void				unEquip(int index);
		int					getIndex(void) const;
		void					on_the_floor(void) const;

	private :
		
		std::string	_name;
		int		_index;
		int		_stock_index;
		AMateria	**_item;
		AMateria	**_stock;
};


#endif