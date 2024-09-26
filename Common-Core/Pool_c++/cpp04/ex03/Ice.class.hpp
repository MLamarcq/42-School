#ifndef ICE_CLASS_HPP
#define ICE_CLASS_HPP

#include "AMateria.class.hpp"

class Ice : public AMateria
{

	public :
			Ice(void);
			Ice(std::string const &type);
			Ice(Ice const &src);
			~Ice (void);

			Ice &operator=(Ice const &rhs);

			void		use(ICharacter &target);
			AMateria*	clone(void) const;
};


#endif