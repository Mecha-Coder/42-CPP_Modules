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

DiamondTrap::DiamondTrap(const std::string& new_name) 
: ClapTrap(new_name + "_clap_name"), name(new_name)
{
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap :" << name << " constructed!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	*this = other;
}

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called.";
}

DiamondTrap::~DiamondTrap()
{ std::cout << "DiamondTrap: " << name  << " destructed!\n"; }

void DiamondTrap::attack(const std::string& target)
{ScavTrap::attack(target);}

void DiamondTrap::whoAmI()
{
    std::cout 
        << "\nDiamondTrap name: " << name 
        << "\nClapTrap name: " << ClapTrap::getName() << std::endl;
}