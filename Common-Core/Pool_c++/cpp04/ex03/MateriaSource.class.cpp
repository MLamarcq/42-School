#include "MateriaSource.class.hpp"

MateriaSource::MateriaSource(void) : _learn_index(0), _follow(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	// this->_learn = new AMateria*[4];
	// for (int i = 0; i < 4; i++)
	// 	this->_learn[i] = NULL;
	// this->_stock = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->_learn[i] = NULL;
	this->_temp = NULL;
	return ;
}

MateriaSource::MateriaSource(std::string type) : _learn_index(0), _follow(0)
{
	std::cout << "MateriaSource type assignement constructor called" << std::endl;
	// this->_learn = new AMateria*[4];
	// for (int i = 0; i < 4; i++)
	// 	this->_learn[i] = NULL;
	// this->_stock = new AMateria*[4];
	// for (int i = 0; i < 4; i++)
	// 	this->_stock[i] = NULL;
	// for (int i = 0; i < 4; i++)
	// 	this->_learn[i] = NULL;
	this->_temp = NULL;

	return ;
	(void)type;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
	return ;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
	std::cout << "MateriaSource copy operator called" << std::endl;
	if (this != &rhs)
	{
		if (this->_learn[0])
		{
			for (int i = 0; this->_learn[i]; i++)
				delete this->_learn[i];
		}
	
	// this->_learn = new AMateria*[4];
		
		for (int i = 0; rhs._learn[i]; i++)
			this->_learn[i] = rhs.getLearn(i);
		this->_learn_index = rhs.getIndex();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	// if (this->_learn)
	// {
	// 	delete [] this->_learn;
	// }
	// if (this->_stock)
	// {
	// 	delete [] this->_stock;
	// }
	// if (this->_learn)
	// {
	// 	for (int i = 0; this->_learn[i]; i++)
	// 		delete this->_learn[i];
	// //}
	std::cout << "Index = " << this->_learn_index << std::endl;
	for (int i = 0; i < this->_learn_index; i++)
  	  delete this->_learn[i];

	// if (this->_temp)
	// 	delete this->_temp;
	return ;
}

AMateria *MateriaSource::getLearn(int index) const
{
	return (this->_learn[index]);
}

int	MateriaSource::getIndex(void) const
{
	return (this->_learn_index);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (this->_learn_index > 3)
	{
		std::cout << "MateriaSource is full, can't add new one" << std::endl;
		return ;
	}
	if (materia->getType().compare("ice") == 0)
	{
		this->_learn[this->_learn_index] = new Ice();
		std::cout << "enter in ice at " << this->_learn_index << std::endl;
	}
	else if (materia->getType().compare("cure") == 0)
	{
		this->_learn[this->_learn_index] = new Cure();
		std::cout << "enter in cure at " << this->_learn_index << std::endl;
	}
	else
	{
		std::cout << "Wrong type of materia" << std::endl;
		return ;
	}
	//this->_learn[_learn_index] = materia;
	this->_learn_index++;
	std::cout << "learn_index = " << this->_learn_index << std::endl;
	delete materia;
	// if (this->_learn[this->_learn_index])
	// {
	// 	delete this->_learn[this->_learn_index];
	// 	this->_learn[this->_learn_index] = NULL; // Pour éviter les pointeurs invalides
	// }
	return ;
}

// AMateria *MateriaSource::createMateria(std::string const &type)
// {
// 	if (type.empty() == 1)
// 	{
// 		std::cout << "You are trying to create a unexistent materia !" << std::cout;
// 		return (NULL);
// 	}
// 	if (type.compare("ice") != 0 && type.compare("cure") != 0)
// 	{
// 		std::cout << "Unknow type. Can't create materia" << std::endl;
// 		return (NULL);
// 	}
// 	if (this->_stock_idx > 3)
// 	{
// 		std::cout << "Too much materia created" << std::endl;
// 		return (NULL);
// 	}
// 	if (this->_follow > 3)
// 	{
// 		std::cout << "No empty place available" << std::endl;
// 		return (NULL);
// 	}
// 	// if (this->_temp)
// 	// 	delete this->_temp;
// 	if (this->_learn[this->_follow]->getType().compare("ice") == 0)
// 	{
// 		// if (this->_temp)
// 	 	// 	delete this->_temp;
// 		this->_temp = new Ice();
// 		this->_temp = this->_learn[this->_follow];
// 		this->_follow++;
// 	}
// 	else if (this->_learn[this->_follow]->getType().compare("cure") == 0)
// 	{
// 		// if (this->_temp)
// 	 	// 	delete this->_temp;
// 		this->_temp = new Cure();
// 		this->_temp = this->_learn[this->_follow];
// 		this->_follow++;
// 	}
// 	//std::cout << "type = " << this->_learn[this->_follow]->getType() << std::endl;
// 	// this->_stock[this->_stock_idx] = this->_learn[this->_follow];
// 	// this->_follow++;
// 	// this->_stock[this->_stock_idx]->setType(type);
// 	// this->_stock_idx++;
// 	return (this->_temp);
// }

// AMateria *MateriaSource::createMateria(std::string const &type)
// {
//     if (type.empty())
//     {
//         std::cout << "You are trying to create a nonexistent materia!" << std::endl;
//         return NULL;
//     }

//     if (type.compare("ice") != 0 && type.compare("cure") != 0)
//     {
//         std::cout << "Unknown type. Can't create materia" << std::endl;
//         return NULL;
//     }

//     if (this->_stock_idx > 3)
//     {
//         std::cout << "Too much materia created" << std::endl;
//         return NULL;
//     }

//     if (this->_follow > 3)
//     {
//         std::cout << "No empty place available" << std::endl;
//         return NULL;
//     }

//     if (type.compare("ice") == 0)
//     {
//         this->_temp = new Ice(*this->_learn[this->_follow]);
//     }
//     else if (type.compare("cure") == 0)
//     {
//         this->_temp = new Cure(*this->_learn[this->_follow]);
//     }

//     if (this->_temp)
//     {
//         this->_temp->setType(type);
//         this->_follow++;
//     }

//     return this->_temp;
// }


AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type.empty())
	{
		std::cout << "You are trying to create a nonexistent materia!" << std::endl;
		return NULL;
	}

	if (type.compare("ice") != 0 && type.compare("cure") != 0)
	{
		std::cout << "Unknown type. Can't create materia" << std::endl;
		return NULL;
	}

	if (this->_learn_index > 4)
	{
		std::cout << "Too much materia created" << std::endl;
		return NULL;
	}

	if (this->_follow > 4)
	{
		std::cout << "No empty place available" << std::endl;
		return NULL;
	}
	if (this->_learn_index > 0 && this->_follow > 0 && this->_learn_index == this->_follow)
	{
		return NULL;
	}
	if (type.compare("ice") == 0)
	{
		this->_temp = new Ice();
		*this->_temp = *this->_learn[this->_follow];
	}
	else if (type.compare("cure") == 0)
	{
		this->_temp = new Cure();
		*this->_temp = *this->_learn[this->_follow];
	}
	if (this->_temp)
	{
		this->_temp->setType(type);
		this->_follow++;
	}

	return this->_temp;
}

