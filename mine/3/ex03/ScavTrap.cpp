/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 23:21:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& new_name) : ClapTrap(new_name)
{
    setHit(100);
    setEnergy(50);
    setAttack(20);
    std::cout << "ScavTrap: " << getName() << " constructed!\n";
}


ScavTrap::~ScavTrap() 
{std::cout << "ScavTrap: " << getName() << " destructed!\n";}


void ScavTrap::guardGate() 
{std::cout << "ScavTrap: " << getName() << " is now in Gatekeeper mode\n";}


void ScavTrap::attack(const std::string& target)
{
    if (getHit() == 0)            
        std::cout << "ScavTrap: Can't attack. " << getName() << " is already dead\n";
    else if (getEnergy() == 0)    
        std::cout << "ScavTrap: Can't attack. " << getName() << " have no hit / energy points left!\n";
    else                          
        std::cout << "ScavTrap: " << getName() << " attack " << target << ", causing " << getAttack() << " damage points\n";
    if (getHit() && getEnergy())
        setEnergy(getEnergy() - 1);
}
