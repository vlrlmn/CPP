/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:50 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/30 14:19:10 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "ClapTrap";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string _name, int _hitPoints, int _energyPoints, int _attackDamage)
{
    name = _name;
    hitPoints = _hitPoints;
    energyPoints = _energyPoints;
    attackDamage = _attackDamage;
    std::cout << "Prametrized constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
    	this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Copy assignment operator called" <<std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " is out of energy or hit points and cannot attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        hitPoints -= amount;
        if (hitPoints < 0)
            hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining hit points: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points! Remaining hit points: " << hitPoints << ", energy points: " << energyPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " cannot repair itself due to lack of energy or being destroyed." << std::endl;
    }
}