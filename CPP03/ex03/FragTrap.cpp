/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:28:41 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/12 18:55:09 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack) :
    ClapTrap(name, hit, energy, attack)
{
    this->hitPoints = hit;
    this->attackDamage = attack;
   std::cout << "FragTrap prametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
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
        std::cout << "fragTrap no hit points" << std::endl;
        return ;
    }
    std::cout << this->name << " FragTrap requested high fives" << std::endl;
}