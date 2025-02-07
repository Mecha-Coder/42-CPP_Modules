/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 21:57:37 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{
    FragTrap frag("Lucas");
    
    std::cout << "\n-----------------------------------------------------\n";
    
    std::cout 
    << "\nHit   : " << frag.getHit()
    << "\nEnergy: " << frag.getEnergy()
    << "\nAttack: " << frag.getAttack() << "\n";


    std::cout << "\n-----------------------------------------------------\n";
    
    frag.attack("enemy2");
    frag.takeDamage(50);
    frag.beRepaired(10);
    frag.highFivesGuys();

    std::cout << "\n-----------------------------------------------------\n";

    std::cout 
    << "\nHit   : " << frag.getHit()
    << "\nEnergy: " << frag.getEnergy()
    << "\nAttack: " << frag.getAttack() << "\n";
    
    std::cout << "\n-----------------------------------------------------\n";
}
