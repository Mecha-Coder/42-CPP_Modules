/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/04 21:44:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() 
{
    
    DiamondTrap diamond("Luffy");
    
    std::cout << "\n-----------------------------------------------------\n";
    
    std::cout 
        << "\nHit   : " << diamond.getHit()
        << "\nEnergy: " << diamond.getEnergy()
        << "\nAttack: " << diamond.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
    
    diamond.attack("Target Dummy");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.whoAmI();

    std::cout << "\n---------\n";

    diamond.highFivesGuys();
    diamond.guardGate();

    std::cout << "\n-----------------------------------------------------\n";

     std::cout 
        << "\nHit   : " << diamond.getHit()
        << "\nEnergy: " << diamond.getEnergy()
        << "\nAttack: " << diamond.getAttack() << "\n";

    std::cout << "\n-----------------------------------------------------\n";
}
