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

ClapTrap::ClapTrap(const std::string& new_name) : name(new_name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name  << " destructed!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoint == 0 || energyPoint == 0) 
    {
        std::cout  << name  << " cannot attack. No hit / energy points left!\n";
        return;
    }
    energyPoint--;
    std::cout << name << " attacks " << target  << ", causing " << attackDamage << " damage points\n"; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoint <= amount) 
    {
        hitPoint = 0;
        std::cout << name  << " took " << amount << " damage and died\n";
    } 
    else 
    {
        hitPoint -= amount;
        std::cout << name  << " took " << amount << " damage and has " << hitPoint << " hit points left!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoint == 0 || energyPoint == 0)
    {
        std::cout << name << " cannot repair. No hit / energy points left!\n";
        return;
    }
    energyPoint--;
    hitPoint += amount;
    std::cout << name << " repaired itself, gaining " << amount << " hit points!\n";
}
