/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 21:55:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
Rule
====
Hit point = health
Attack and Repair = -1 energy points
Do nothing if attack / energy = 0 

attack
-> it causes its target to lose <attack damage> hit points

repair
-> repairs itself, it gets <amount> hit points back

take
-> reduce hit point by <attack damage>
*/
int main() 
{
    ClapTrap clap("Harry");
    
    std::cout << "\n-----------------------------------------------------\n";

    std::cout 
    << "\nHit   : " << clap.getHit()
    << "\nEnergy: " << clap.getEnergy()
    << "\nAttack: " << clap.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.attack("target_A");
    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.takeDamage(3);

    std::cout << "\n-----------------------------------------------------\n";

    std::cout 
    << "\nHit   : " << clap.getHit()
    << "\nEnergy: " << clap.getEnergy()
    << "\nAttack: " << clap.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";

    clap.beRepaired(5);
    clap.beRepaired(5);
    clap.attack("target_A");
    clap.takeDamage(6);
    clap.beRepaired(4);
    clap.takeDamage(3);

    std::cout << "\n-----------------------------------------------------\n";
}
