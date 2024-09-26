/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamarcq <mlamarcq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:32:12 by mael              #+#    #+#             */
/*   Updated: 2023/10/19 12:03:23 by mlamarcq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "dog.class.hpp"
#include "cat.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	Animal* a =  new Animal();
	Animal* b = new Dog();
	Animal* c = new Dog("Bernard");
	Animal *d = new Cat("Manfred");
	WrongAnimal *e = new WrongAnimal();
	WrongAnimal *f = new WrongCat();

	std::cout << std::endl;

	a->makeSound();
	b->makeSound();
	c->makeSound();
	d->makeSound();
	e->makeSound();
	f->makeSound();
	
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;

	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl << std::endl;
	
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete meta;
	// delete j;
	// delete i;
		
	return (0);
}