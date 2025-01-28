/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 16:14:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() 
{
    std::cout << "\n-----------------------------------------------------\n";
    ClapTrap clap("Clappy");
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.attack("target2");
    clap.takeDamage(12);
    clap.beRepaired(4);


    std::cout << "\n-----------------------------------------------------\n";

    ScavTrap scav("Scavvy");
    scav.attack("enemy1");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n-----------------------------------------------------\n";
}
