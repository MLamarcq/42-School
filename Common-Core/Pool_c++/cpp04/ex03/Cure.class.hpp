#ifndef CURE_CLASS_HPP
#define CURE_CLASS_HPP

#include "AMateria.class.hpp"

class Cure : public AMateria
{
	public :
			Cure(void);
			Cure(std::string const &type);
			Cure(Cure const &src);
			~Cure (void);

			Cure &operator=(Cure const &rhs);

			void		use(ICharacter &target);
			AMateria*	clone(void) const;
};

#endif