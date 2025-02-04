/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:30:01 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 16:35:12 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& initName) : ClapTrap(initName) 
{
    setHit(100);
    setEnergy(100);
    setAttack(30);
    std::cout << "FragTrap: " << getName() << " constructed!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " << getName() << " destructed!\n";
}

void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap: " << getName() << " requests a high five!🙌\n";
}