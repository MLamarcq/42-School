/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:43 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 14:01:31 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.class.hpp"

Dog::Dog(void) : Aanimal()
{
	std::cout << "Dog default constructor called\n" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain("Bones, Bones, Bones, Bones...");
	std::cout << std::endl;
	return ;
}

Dog::Dog(std::string type) : Aanimal(type)
{
	std::cout << "Type assignement dog constructor called\n" << std::endl;
	if (type.compare("Dog") != 0)
	{
		std::cout << "Hum, don't mess with me. A dog is a DOG, not " << type << "!" << std::endl;
		std::cout << "It's type is Dog. No deal" << std::endl;
		this->_type = "Dog";
	}
	else
		this->_type = type;
	this->_brain = new Brain("Bones, Bones, Bones, Bones...");
	std::cout << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Aanimal(src)
{
	std::cout << "Copy dog constructor called\n" << std::endl;
	this->_brain = NULL;
	*this = src;
	return ;
}

Dog	&	Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog operator assignement called\n" << std::endl;
	if (this != &rhs)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->fillIdea(i, rhs.GetIdeas(i));
		this->_type = rhs.getType();
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "I am a " << this->_type << " ! Listen : whouf whouf\n" << std::endl;
	return ;
}

std::string	Dog::GetIdeas(int idea) const
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

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::ChooseIdea(std::string idea, int target, int start, int end)
{
	this->_brain->chooseIdea(idea, target, start, end);
	return ;
}


void	Dog::PrintIdea(bool choice, int idea) const
{
	this->_brain->printIdea(choice, idea);
	return ;
}

void	Dog::ChooseSpecificIdea(void)
{
	this->_brain->chooseSpecificIdea();
	return ;
}