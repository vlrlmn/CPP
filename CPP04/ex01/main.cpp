/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:03:49 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/11 12:06:51 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void subjectTest()
{
	std::cout << "----------------- mandatory test -----------------\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;
}

void arrayTest()
{
	std::cout << "----------------- array test -----------------\n";
	int animalAmount = 10;
	Animal *arr[animalAmount];
	for (int i = 0; i < animalAmount; i++)
	{
		std::cout << i << ":\t";
		if (i % 2 == 0)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}
	std::cout << "----------------- array filled -----------------\n";

	for (int i = 0; i < animalAmount; i++)
	{
		std::cout << i << ":\t";
		delete arr[i];
	}
	std::cout << "----------------- array delited -----------------\n";
	
}

void deepCopyTest()
{
	std::cout << "----------------- deepCopy test -----------------\n";
	
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "\ttmp    :" << tmp.getBrain() << std::endl;
		std::cout << "\tbasic1 :" << basic.getBrain() << std::endl;
	}
	std::cout << "\tbasic2  :" << basic.getBrain() << std::endl;

}

void deleteTest()
{
	const Cat *cat2 = new Cat();
	delete cat2;
}

int main (void)
{
	subjectTest();
	arrayTest();
	deepCopyTest();
	deleteTest();
	std::cout << "-----------------------------------------------------" << std::endl;
}