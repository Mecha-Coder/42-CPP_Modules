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

#include "DiamondTrap.hpp"

int main() 
{
    std::cout << "\n-----------------------------------------------------\n";
    
    DiamondTrap diamond("Diamond");
    diamond.attack("Target Dummy");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.whoAmI();

    std::cout << "\n-----------------------------------------------------\n";
}
