#include "Cure.class.hpp"
#include "AMateria.class.hpp"

Cure::Cure(void) : AMateria()
{
	std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return ;
}
Cure::Cure(std::string const &type) : AMateria(type)
{
	std::cout << "Cure type assignement constructor called" << std::endl;
	this->_type.erase();
	this->_type = "cure";
	return ;
}
Cure::Cure(Cure const &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this= src;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}
Cure &Cure::operator=(Cure const &rhs)
{
	std::cout << "Cure assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

void	Cure::use(ICharacter &target)
{
	std::string temp = target.getName();
	if (temp.empty() == 1)
	{
		std::cout << "Character has no name" << std::endl;
		return ;
	}
	if (is_letter(temp) == 0)
	{
		std::cout << "Wrong name" << std::endl;
		return ;
	}
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}
