/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:05:47 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/25 16:44:22 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void testDeepCopyCharacter()
{
    std::cout << "Testing deep copy of Character" << std::endl;
    
    Character original("Original");
    original.equip(new Ice());
    original.equip(new Cure());

    Character clone = original;

    std::cout << "Original Name: " << original.getName() << std::endl;
    std::cout << "Clone Name: " << clone.getName() << std::endl;

    std::cout << "Using materia from original character:" << std::endl;
    original.use(0, original);
    original.use(1, original);

    std::cout << "Using materia from cloned character:" << std::endl;
    clone.use(0, clone);
    clone.use(1, clone);

    original.unequip(0);
    std::cout << "After unequipping from original, using materia from cloned character: " << std::endl;
    clone.use(0, clone);

    std::cout << "Deep copy test of Character completed." << std::endl;
}

void testDeepCopyMateriaSource()
{
    std::cout << "\nTesting deep copy of MateriaSource" << std::endl;
    
    MateriaSource originalSource;
    originalSource.learnMateria(new Ice());
    originalSource.learnMateria(new Cure());

    MateriaSource cloneSource = originalSource;

    AMateria* materiaFromOriginal = originalSource.createMateria("ice");
    AMateria* materiaFromClone = cloneSource.createMateria("ice");

    std::cout << "Using materia created by original source:" << std::endl;
    if (materiaFromOriginal)
    {
        Character temp("temp");
        materiaFromOriginal->use(temp);
    }

    delete materiaFromOriginal;
    delete materiaFromClone;

    std::cout << "Deep copy test of MateriaSource completed." << std::endl;
}

int main()
{

    std::cout << "=== Initial Basic Test ===" << std::endl;

	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	delete ice;
	delete cure;

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;
    tmp = src->createMateria("stone");
	me->equip(tmp);
	delete tmp;
    

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

    std::cout << "\n=== Testing Deep Copy of Character ===" << std::endl;
    testDeepCopyCharacter();

    std::cout << "\n=== Testing Deep Copy of MateriaSource ===" << std::endl;
    testDeepCopyMateriaSource();

	return 0;
}