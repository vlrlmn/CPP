/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:28:41 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/02 17:47:29 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    std::cout << "FragTrap prametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
    	this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap copy assignment operator called" <<std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
      std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->energyPoints == 0)
    {
        std::cout << "fragTrap no energy points" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0)
    {
        std::cout << "fragTrap no energy points" << std::endl;
        return ;
    }
    std::cout << this->name << " FragTrap requested high fives" << std::endl;
}