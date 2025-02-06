/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:25:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 15:18:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap 
{
    protected:
        std::string name;
        unsigned int hitPoint;
        unsigned int energyPoint;
        unsigned int attackDamage;

    public:
        ClapTrap(void);
        ClapTrap(const std::string& new_name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();
        
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int getHit();
        unsigned int getEnergy();
        unsigned int getAttack();
        std::string getName();

        void setHit(unsigned int amount);
        void setEnergy(unsigned int amount);
        void setAttack(unsigned int amount);
};

#endif