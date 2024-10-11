/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:12:50 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/02 17:41:51 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "ClapTrap";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string _name)
{
    if (!_name.empty())
        name = _name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap prametrized constructor called" << std::endl;
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
    std::cout << "ClapTrap copy assignment operator called" <<std::endl;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if (target.empty())
    {
        std::cout << "Target not valid!\n";
        return;
    }

    if (energyPoints == 0)
    {
        printWarning('E', "attack");
        return;
    }

    if (hitPoints == 0)
    {
        printWarning('H', "attack");
        return;
    }

    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " 
              << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        printWarning('H', "take damage");
        return;
    }

    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! "
              << "Remaining hit points: " << hitPoints << std::endl;

    if (hitPoints == 0)
        printWarning('H', "take damage");
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
    {
        printWarning('E', "be repaired");
        return;
    }

    if (hitPoints == 0)
    {
        printWarning('H', "be repaired");
        return;
    }

    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, recovering " 
              << amount << " hit points! Remaining hit points: " << hitPoints 
              << ", energy points: " << energyPoints << std::endl;
}

void ClapTrap::printWarning(char flag, const std::string& action) const
{
    if (flag == 'E')
        std::cout << "Not enough energy points to " << action << "!\n";
    if (flag == 'H')
        std::cout << "Not enough hit points to " << action << "!\n";
}

void ClapTrap::printState() const
{
    std::cout << name << " has:\n";
    std::cout << "\tHit points: " << hitPoints << std::endl;
    std::cout << "\tEnergy points: " << energyPoints << std::endl;
    std::cout << "\tAttack damage: " << attackDamage << std::endl;
}