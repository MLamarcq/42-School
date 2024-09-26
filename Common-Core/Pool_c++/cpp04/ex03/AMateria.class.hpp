#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

#include <string>
#include <iostream>
#include "ICharacter.class.hpp"

class AMateria
{

	public :

			AMateria(void);
			AMateria(std::string const & type);
			AMateria(AMateria const &src);
			virtual ~AMateria(void);

			AMateria &operator=(AMateria const &rhs);

			std::string const &getType(void) const;
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target) = 0;
			virtual void	setType(std::string type);

	protected :

			std::string  _type;
};

int	is_letter(std::string str);

#endif