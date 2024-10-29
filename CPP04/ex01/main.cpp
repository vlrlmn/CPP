/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:03:49 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/29 10:45:02 by lomakinaval      ###   ########.fr       */
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

	delete j;
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
	std::cout << "----------------- array deleted -----------------\n";
	
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

void assignmentTest()
{
	std::cout << "---------------- assignment test ----------------\n";
	Dog dog1;
	Dog dog2;
	dog2 = dog1;

	dog1.getBrain()->getIdea(0) = "Chase the ball";
	dog2.getBrain()->getIdea(0) = "Be a good boy";
	
	std::cout << "dog1 Brain: " << dog1.getBrain() << std::endl;
	std::cout << "dog2 Brain: " << dog2.getBrain() << std::endl;

	std::cout << "dog1 brain idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 brain idea: " << dog2.getBrain()->getIdea(0) << std::endl;

}

void brainIdeasTest()
{
	std::cout << "----------------- brain ideas test ----------------\n";
	Dog dog1;
	Dog dog2 = dog1;

	dog1.getBrain()->getIdea(0) = "Chase the ball";
	dog2.getBrain()->getIdea(0) = "Be a good boy";

	std::cout << "dog1 brain idea: " << dog1.getBrain()->getIdea(10) << std::endl;
	std::cout << "dog2 brain idea: " << dog2.getBrain()->getIdea(0) << std::endl;
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
	assignmentTest();
	brainIdeasTest();
	deleteTest();
	std::cout << "-----------------------------------------------------" << std::endl;
}