#include "Ice.class.hpp"
#include "AMateria.class.hpp"

Ice::Ice(void) : AMateria()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
	return ;
}
Ice::Ice(std::string const &type) : AMateria(type)
{
	std::cout << "Ice type assignement constructor called" << std::endl;
	this->_type.erase();
	this->_type = "ice";
	return ;
}
Ice::Ice(Ice const &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}
Ice &Ice::operator=(Ice const &rhs)
{
	std::cout << "Ice assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

void	Ice::use(ICharacter &target)
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
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}
