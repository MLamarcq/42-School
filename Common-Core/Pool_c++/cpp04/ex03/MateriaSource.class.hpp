#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

#include "IMateriaSource.class.hpp"
#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"

class MateriaSource : public IMateriaSource
{
		public :

				MateriaSource(void);
				MateriaSource(std::string type);
				MateriaSource(MateriaSource const &src);
				~MateriaSource(void);

				MateriaSource &operator=(MateriaSource const &rhs);

				void learnMateria(AMateria *materia);
				AMateria* createMateria(std::string const & type);
				AMateria *getLearn(int index) const;
				int		getIndex(void) const;

		private :

				AMateria	*_learn[4];
				//AMateria	**_stock;
				AMateria	*_temp;
				int			_learn_index;
				//int			_stock_idx;
				int			_follow;

};


#endif