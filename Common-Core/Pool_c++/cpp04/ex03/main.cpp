#include "AMateria.class.hpp"
#include "ICharacter.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "MateriaSource.class.hpp"
#include "IMateriaSource.class.hpp"
#include "Character.class.hpp"

// int main()
// {
// 	Ice a("Jean-Luc");
// 	Cure b;

// 	std::cout << "type = " << a.getType() << std::endl;
// 	std::cout << "type = " << b.getType() << std::endl;

// 	return (0);
// }

// int main()
// {
// 		IMateriaSource* src = new MateriaSource();
// 		std::cout << std::endl;
// 		src->learnMateria(new Ice());
// 		std::cout << std::endl;
// 		src->learnMateria(new Cure());
// 		std::cout << std::endl;
// 		src->learnMateria(new Ice());
// 		std::cout << std::endl;
// 		src->learnMateria(new Cure());
		
// 		ICharacter* me = new Character("me");
		
// 		AMateria* tmp;
		
// 		tmp = src->createMateria("ice");
// 		me->equip(tmp);
// 		tmp = src->createMateria("cure");
// 		me->equip(tmp);
// 		tmp = src->createMateria("ice");
// 		me->equip(tmp);
// 		tmp = src->createMateria("cure");
// 		me->equip(tmp);
		
		
// 		ICharacter* bob = new Character("bob");
		
// 		me->use(0, *bob);
// 		me->use(1, *bob);
// 		me->use(2, *bob);
// 		me->use(3, *bob);
		
// 	//	me->unEquip(1);
// 		me->unEquip(1);
// 		//me->unEquip(3);
// 		me->on_the_floor();

// 		tmp = src->createMateria("cure");
// 		me->equip(tmp);

// 		me->use(0, *bob);
// 		me->use(1, *bob);
// 		me->use(2, *bob);
// 		me->use(3, *bob);
		

// 		//me->on_the_floor();


// 		delete bob;
// 		delete me;
// 		delete src;
// 		return (0);
// }

int main()
{
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;
		src->learnMateria(new Ice());
		std::cout << std::endl;
		src->learnMateria(new Cure());
		std::cout << std::endl;
		src->learnMateria(new Ice());
		std::cout << std::endl;
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		
		me->unEquip(1);
	// 	me->unEquip(1);
	// 	//me->unEquip(3);
	// 	me->on_the_floor();

	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);

	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	me->use(2, *bob);
	// 	me->use(3, *bob);
		

		//me->on_the_floor();


		delete bob;
		delete me;
		delete src;
		return (0);
}