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
    hitPoint = 100;
    energyPoint = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}