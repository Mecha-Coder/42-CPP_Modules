/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 16:28:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

    FragTrap frag("Fraggy");
    frag.attack("enemy2");
    frag.takeDamage(50);
    frag.beRepaired(40);
    frag.highFivesGuys();

    std::cout << "\n-----------------------------------------------------\n";
}
