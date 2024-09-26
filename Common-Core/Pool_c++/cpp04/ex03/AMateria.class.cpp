#include "AMateria.class.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}
AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria setting type constructor called" << std::endl;
	this->_type = type;
	this->_type.erase();
	return ;
}
AMateria::AMateria(AMateria const &src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
	return ;
}
AMateria::~AMateria(void)
{
	std::cout << "AMaterial destructor called" << std::endl;
	return ;
}
AMateria & AMateria::operator=(AMateria const &rhs)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::setType(std::string type)
{
	this->_type = type;
	return ;
}