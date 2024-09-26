/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:50:21 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 13:49:26 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.class.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor called\n" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain("Mouse, Mouse, Mouse, Mouse ...");
	return ;
}
Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat name assignement constructor called\n" << std::endl;
	if (type.compare("Cat") != 0)
	{
		std::cout << "Did you really try to call a cat " << this->_type << "?!" << std::endl;
		std::cout << "Sorry, but a cat is a Cat !" << std::endl;
		this->_type = "Cat";
	}
	else
		this->_type = type;
	this->_brain = new Brain("Mouse, Mouse, Mouse, Mouse ...");
	std::cout << std::endl;
	return ;
}
Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called\n" << std::endl;
	this->_brain = NULL;
	*this = src;
	return ;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat copy operator called\n" << std::endl;
	if (this != &rhs)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->fillIdea(i, rhs.GetIdeas(i));
		this->_brain  = rhs._brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " do you want some sweetness? Miaou :)\n" << std::endl;
	return ;
}

std::string	Cat::GetIdeas(int idea) const
{
	if (idea >= 0 && idea <= 99)
		return (this->_brain->getIdeas(idea));
	else
	{
		std::cout << "You are trying to reach an idea that does not exist ! " << std::endl;
		std::cout << "Don't forget, there is 100 idea only !" << std::endl;
	}
	return ("yo");
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::ChooseIdea(std::string idea, int target, int start, int end)
{
	this->_brain->chooseIdea(idea, target, start, end);
	return ;
}


void	Cat::PrintIdea(bool choice, int idea) const
{
	this->_brain->printIdea(choice, idea);
	return ;
}

void	Cat::ChooseSpecificIdea(void)
{
	this->_brain->chooseSpecificIdea();
	return ;
}