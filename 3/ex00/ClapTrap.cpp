/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:48:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 15:28:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

ClapTrap::ClapTrap()
{std::cout << "ClapTrap: Default constructor called. No data initialized\n";}

ClapTrap::ClapTrap(str new_name) 
: name(new_name), hitPoint(10), energyPoint(10), attackDamage(0)
{ std::cout << "ClapTrap: " << name << " constructed!\n"; }

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
	std::cout << "ClapTrap: Copy from" << other.name << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.getName();
        hitPoint = other.getHit();
        energyPoint = other.getEnergy();
        attackDamage = other.getAttack();
    }
    return (*this);
    
}

ClapTrap::~ClapTrap()
{ std::cout << "ClapTrap: " << name  << " destructed!\n"; }

//------------------------------------------------------------------------
// Methods

void ClapTrap::attack(const str& target)
{   
    if (hitPoint == 0)            
        std::cout << "ClapTrap: Can't attack. " << name  << " is already dead\n";
    else if (energyPoint == 0)
        std::cout << "ClapTrap: Can't attack. " << name << " have no hit / energy points left!\n";
    else
        std::cout << "ClapTrap: " << name << " attack " << target << ", causing " << attackDamage << " damage points\n";
    if (hitPoint && energyPoint)
        energyPoint--;
}

void ClapTrap::takeDamage(uint amount)
{
    if (hitPoint == 0)
        std::cout << "ClapTrap: " << name  << " is already dead. Please stop attacking\n";
    else if (hitPoint <= amount) 
    {
        hitPoint = 0;
        std::cout << "ClapTrap: " << name  << " took " << amount << " damage and died\n";
    }
    else 
    {
        hitPoint -= amount;
        std::cout << "ClapTrap: " << name  << " took " << amount << " damage and has " << hitPoint << " hit points left!\n";
    }
}

void ClapTrap::beRepaired(uint amount)
{
    if (hitPoint == 0)
        std::cout << "ClapTrap: " << "Can't repair. " << name  << " is already dead\n";
    else if (energyPoint == 0)
        std::cout << "ClapTrap: " << name << " cannot repair. No hit / energy points left!\n";
    else
    {
        energyPoint--;
        hitPoint += amount;
        std::cout << "ClapTrap: " << name << " repaired itself, gaining " << amount << " hit points!\n";
    }
}

//------------------------------------------------------------------------
// Setter and getter

uint ClapTrap::getHit() const {return hitPoint;}
uint ClapTrap::getEnergy() const {return energyPoint;}
uint ClapTrap::getAttack() const {return attackDamage;}
str ClapTrap::getName() const { return name;}

void ClapTrap::setHit(uint amount) {hitPoint = amount;}
void ClapTrap::setEnergy(uint amount) {energyPoint = amount;}
void ClapTrap::setAttack(uint amount) {attackDamage = amount;}
void ClapTrap::setName(str new_name) {name = new_name;}
