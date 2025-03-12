/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:30:01 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/07 16:42:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

FragTrap::FragTrap()
{
    std::cout << "FragTrap: Default constructor called. Put initial value\n";
    hitPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(str new_name) : ClapTrap() 
{
    name = new_name;
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
    std::cout << "FragTrap: " << name << " constructed!\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name)
{
    *this = other;
	std::cout << "FragTrap: Copy from" << other.name << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{std::cout << "FragTrap: " << name << " destructed!\n";}

//------------------------------------------------------------------------
// Methods

void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap: " << name << " requests a high five!🙌\n";
}