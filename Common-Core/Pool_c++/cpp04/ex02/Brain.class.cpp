/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:48:02 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 13:50:21 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	this->fillBrain("No Idea");
	return ;
}
Brain::Brain(std::string name)
{
	std::cout << "Brain set idea constructor called" << std::endl;
	std::cout << "Idea = " << name << std::endl;
	this->fillBrain(name);
	return ;
}
Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain & Brain::operator=(Brain const &rhs)
{
	int i = 0;
	std::cout << "Brain assignement operator called" << std::endl;
	if (this != &rhs)
	{
		while (i < 100)
		{
			if (!(rhs._ideas[i].empty()))
				this->_ideas[i] = rhs.getIdeas(i);
			else
			{
				std::cout << "Ideas n*" << i << " not set. Copy impossible" << std::endl;
				std::cout << "You copied " << i << " ideas. We stop" << std::endl; 
				return (*this);
			}
			i++;
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

void	Brain::fillIdea(int index, std::string idea)
{
	if (index >= 0 && index <= 99)
		this->_ideas[index] = idea;
	else
		std::cout << "You are tried to reach an idea that is not in the brain !" << std::endl;
	return ;
}

std::string Brain::getIdeas(int i) const
{
	if (i >= 0 && i <= 99)
		return (this->_ideas[i]);
	else
		std::cout << "You are tried to reach an idea that is not in the brain !" << std::endl;
	return ("Try later !");
}

void	Brain::fillBrain(std::string idea)
{
	int i = 0;
	
	if (idea.size() < 1)
	{
		std::cout << "We need an idea !" << std::endl;
		return ;
	}
	while (i < 100)
	{
		this->_ideas[i] = idea;
		i++;
	}
	return ;
}
void	Brain::chooseIdea(std::string idea, int target, int start, int end)
{
	if (idea.size() < 1)
	{
		std::cout << "An idea is not the void ! Wait.. It's too philosophical for me" << std::endl;
		return ;
	}
	// if (is_correct(idea) == 0)
	// {
	// 	std::cout << "An idea is only coposed with letters or numbers" << std::endl;
	// 	return ;
	// }
	if (target < 0 || target > 100 || start < 0 || start > 100 || end > 100 || end < 0)
	{
		std::cout << "Your target, start and end can not be negative or bigger than 100. Impossible to choose idea" << std::endl;
		return ;
	}
	if (start != 0 && (start >= end))
	{
		std::cout << "You can't set a field of idea with an end inferior or equal to the start" << std::endl;
		return ;
	}
	this->_ideas[target] = idea;
	if (end != 0)
	{
		while (start <= end)
		{
			this->_ideas[start] = idea;
			start++;
		}
	}
	return ;
}

void	Brain::chooseSpecificIdea(void)
{
	std::string input;
	std::string input2;
	bool		check = false;
	int			i = 0;
	int			save;
	
	std::cout << "This fonctionnality allows you to set specific ideas" << std::endl;
	std::cout << "First, choose the number (type 'Stop' if you change your mind) of ideas you want to set (5 ideas max) : ";
	while (check == false)
	{
		if (!(std::getline(std::cin, input)))
		{
			std::cout << "Getline fail" << std::endl;
			return ;
		}
		if (input.compare("Stop") == 0)
		{
			check = true;
			return;
		}
		if (is_digit(input) == 1)
		{
			if (std::atoi(input.c_str()) > 5)
				std::cout << "We are limited to 5 idea in one time. Please retry : ";
			else if (std::atoi(input.c_str()) < 0)
				std::cout << "No negative value or out of int range please. Please retry : ";
			else if (std::atoi(input.c_str()) == 0)
			{
				std::cout << "Alrigt, no ideas will be set" << std::endl;
				check = true;
			}
			else
			{
				save = std::atoi(input.c_str());
				while (i < save)
				{
					std::cout << "Choose the idea to choose (beteween 0 and 99) : ";
					std::string idea;
					int			index;
					bool		toggle1 = false;
					bool		toggle2 = false;
					while (toggle1 == false)
					{
						if (!(std::getline(std::cin, input2)))
						{
							std::cout << "Getline fail" << std::endl;
							return ;
						}
						index = std::atoi(input2.c_str());
						if (is_digit(input2) == 0)
							std::cout << "We meant a number : ";
						else if (index < 0 || index > 99)
						{
							std::cout << "Error. Choose a number between 0 and 99 : ";
							input2.erase();
						}
						else
							toggle1 = true;
					}
					// index = std::atoi(input2.c_str());
					// while (index < 0 || index > 99)
					// {
					// 	std::cout << "Error. Choose a number between 0 and 99 : ";
					// 	input2.erase();
					// 	if (!(std::getline(std::cin, input2)))
					// 	{
					// 		std::cout << "Getline failed" << std::endl;
					// 		return ;
					// 	}
					// 	index = std::atoi(input2.c_str());
					// }
					input2.erase();
					std::cout << "Now describe the idea with words : ";
					while (toggle2 == false)
					{
						if (!(std::getline(std::cin, input2)))
						{
							std::cout << "Getline fail" << std::endl;
							return ;
						}
						if (is_correct(input2) == 0)
							std::cout << "Wrong input. Try again : ";
						else
						{
							idea = input2;
							toggle2 = true;
						}
					}
					this->_ideas[index] = idea;
					input2.erase();
					idea.erase();
					i++;
				}
				check = true;
			}
		}
		//else if (is_digit(input) == 0)
		else
			std::cout << "We want a number between 0 and 5 : ";
	}
	return ;
}

void	Brain::printIdea(bool choice, int idea) const
{
	int i = 0;
	if (choice == true)
	{
		while (i < 100)
		{
			if (this->_ideas[i].empty())
			{
				std::cout << "Idea n*" << i << " is not set. Can't continue" << std::endl;
				return ;
			}
			std::cout << "This is idea n*" << i << " : " << this->_ideas[i] << std::endl;
			i++;
		}
		return ;
	}
	else
	{
		if (idea < 0 || idea > 100)
		{
			std::cout << "Wrong idea format (need number between 0 and 100). Can't print" << std::endl;
			return ;
		}
		std::cout << "Only one idea is printed\n" << std::endl;
		std::cout << "Idea n*" << idea << " is " << this->_ideas[idea] << std::endl;
	}
	return ;
}