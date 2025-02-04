/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 19:03:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& new_name) 
: ClapTrap(new_name + "_clap_name"), FragTrap(new_name), ScavTrap(new_name), name(new_name)
{
    ClapTrap::setHit(FragTrap::getHit());
    ClapTrap::setEnergy(ScavTrap::getAttack());
    ClapTrap::setAttack(FragTrap::getAttack());
    std::cout << "DiamondTrap :" << name << " constructed!\n";
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