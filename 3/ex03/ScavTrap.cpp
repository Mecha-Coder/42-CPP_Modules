/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/07 16:42:14 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap: Default constructor called. Put initial value\n";
    energyPoint = 50;
}

ScavTrap::ScavTrap(str new_name) : ClapTrap()
{
    name = new_name;
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap: " << name << " constructed!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name)
{
    *this = other;
	std::cout << "ScavTrap: Copy from" << other.name << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
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

ScavTrap::~ScavTrap() 
{std::cout << "ScavTrap: " << name << " destructed!\n";}

//------------------------------------------------------------------------
// Methods

void ScavTrap::attack(const str& target)
{
    if (getHit() == 0)            
        std::cout << "ScavTrap: Can't attack. " << name << " is already dead\n";
    else if (getEnergy() == 0)    
        std::cout << "ScavTrap: Can't attack. " << name << " have no hit / energy points left!\n";
    else                          
        std::cout << "ScavTrap: " << name << " attack " << target << ", causing " << getAttack() << " damage points\n";
    if (getHit() && getEnergy())
        setEnergy(getEnergy() - 1);
}

void ScavTrap::guardGate() 
{std::cout << "ScavTrap: " << name << " is now in Gatekeeper mode\n";}

