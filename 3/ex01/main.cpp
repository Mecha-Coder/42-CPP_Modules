/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 21:56:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
Rule
====
- constructor, destructor & attack print different message
- proper constructor & destructor chaining
*/

int main() 
{

    ScavTrap scav("Scavvy");
    
    std::cout << "\n-----------------------------------------------------\n";

    std::cout 
    << "\nHit   : " << scav.getHit()
    << "\nEnergy: " << scav.getEnergy()
    << "\nAttack: " << scav.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
    
    scav.attack("enemy1");
    scav.attack("enemy1");
    scav.attack("enemy1");
    scav.takeDamage(30);
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n-----------------------------------------------------\n";

     std::cout 
    << "\nHit   : " << scav.getHit()
    << "\nEnergy: " << scav.getEnergy()
    << "\nAttack: " << scav.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
}
