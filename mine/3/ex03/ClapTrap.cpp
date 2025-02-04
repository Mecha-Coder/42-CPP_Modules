/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:48:59 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 23:28:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& new_name) 
: name(new_name), hitPoint(10), energyPoint(10), attackDamage(0)
{ std::cout << "ClapTrap: " << name << " constructed!\n"; }


ClapTrap::~ClapTrap()
{ std::cout << "ClapTrap: " << name  << " destructed!\n"; }


void ClapTrap::attack(const std::string& target)
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


void ClapTrap::takeDamage(unsigned int amount)
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


void ClapTrap::beRepaired(unsigned int amount)
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


unsigned int ClapTrap::getHit() {return hitPoint;}
unsigned int ClapTrap::getEnergy() {return energyPoint;}
unsigned int ClapTrap::getAttack() {return attackDamage;}
std::string ClapTrap::getName(){ return name;}

void ClapTrap::setHit(unsigned int amount) {hitPoint = amount;}
void ClapTrap::setEnergy(unsigned int amount) {energyPoint = amount;}
void ClapTrap::setAttack(unsigned int amount) {attackDamage = amount;}
void ClapTrap::setName(const std::string& new_name) {name = new_name;}
