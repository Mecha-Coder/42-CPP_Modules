/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:00:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 15:31:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
    ClapTrap clap("Harry");

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


    std::cout << "\n-----------------------------------------------------\n";


    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.takeDamage(3);
    clap.beRepaired(5);
    clap.attack("target_A");
    clap.takeDamage(6);
    clap.beRepaired(4);

    std::cout << "\n-----------------------------------------------------\n";
}
