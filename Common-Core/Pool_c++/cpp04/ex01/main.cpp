/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 13:46:32 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "dog.class.hpp"
#include "cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include "Brain.class.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	j->makeSound();
	i->makeSound();
	
	Animal *animalHorde[20];

	for (int i = 0; i < 10; i++)
	{
		animalHorde[i] = new Dog();
	}
	for (int i = 10; i < 20; i++)
	{
		animalHorde[i] = new Cat();
	}


	for (int i = 0; i < 20; i++)
		animalHorde[i]->makeSound();

	
	animalHorde[0]->ChooseIdea("J'aime les os", 0, 10, 20);
	animalHorde[1]->PrintIdea(true, 0);
	std::cout << std::endl;
	animalHorde[0]->PrintIdea(true, 0);
	animalHorde[0]->ChooseSpecificIdea();
	animalHorde[0]->PrintIdea(true, 0);


	for (int i = 0; i < 10; i++)
	{
		delete animalHorde[i];
	}
	for (int i = 10; i < 20; i++)
	{
		delete animalHorde[i];
	}
	

	
	delete j;//should not create a leak
	delete i;

	return 0;

/*****************************************************************************/
	// Cat Tom("Fichtre");
	// Dog Medor;
	
	// Tom.ChooseIdea("MORE MOUSE", 98, 30, 50);
	// Tom.PrintIdea(true, 0);

	// Medor.PrintIdea(true, 0);
	// Medor.ChooseIdea("MORE BONES", 12, 88, 99);
	// Medor.PrintIdea(true, 0);
	
	// Dog Milou(Medor);

	// Medor.ChooseIdea("Hide Idea", 0, 50, 99);
	
	// Milou.PrintIdea(true, 0);

	// Milou = Medor;
	// Milou.PrintIdea(true, 0);
	// return (0);
}