/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 16:09:34 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoint == 0 || energyPoint == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack. No hit points or energy points left!" << std::endl;
        return;
    }
    energyPoint--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}