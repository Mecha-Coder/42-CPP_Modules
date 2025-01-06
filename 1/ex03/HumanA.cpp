/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:51:02 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 13:10:03 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon& w)
{
    name = n;
    weapon = &w;
}

void HumanA::attack(void)
{   
    std::cout
        << name
        << " attacks with their "
        << weapon->getType()
        << std::endl; 
}
