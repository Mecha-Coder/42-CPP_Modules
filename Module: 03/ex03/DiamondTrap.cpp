/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 23:18:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

DiamondTrap::DiamondTrap() 
{std::cout << "DiamondTrap: Default constructor called. No data initialized\n";}

DiamondTrap::DiamondTrap(str new_name) : ClapTrap(new_name + "_clap_name")
{
	name = new_name;
	hitPoint = FragTrap::hitPoint;
	energyPoint = ScavTrap::energyPoint;
	attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap: " << name << " constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
: ClapTrap(other), FragTrap(other), ScavTrap(other) 
{
	*this = other;
	std::cout << "DiamondTrap: Copy from" << other.name << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
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

DiamondTrap::~DiamondTrap()
{ std::cout << "DiamondTrap: " << name  << " destructed!\n"; }

//------------------------------------------------------------------------
// Methods

void DiamondTrap::whoAmI() const
{
    std::cout 
        << "\nHow Am I\n"
        << "--------------------------------------"
        << "\nDiamondTrap name: " << name 
        << "\nClapTrap name   : " << ClapTrap::getName() << std::endl;
}