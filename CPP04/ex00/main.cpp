/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:03:49 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/08 17:34:34 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void subjectTests()
{
	std::cout << "----------------- mandatory tests -----------------\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;
}

void externalTests()
{
	std::cout << "\n----------------- external tests -----------------\n";
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *wrongKitty = new WrongCat();
	const WrongCat *wCat = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << wrongKitty->getType() << " " << std::endl;
	std::cout << wCat->getType() << " " << std::endl;
	wrongKitty->makeSound();
	meta->makeSound();
	wCat->makeSound();

	delete wrongKitty;
	delete meta;
	delete wCat;
}

int main()
{
	subjectTests();
	externalTests();
	return 0;
}