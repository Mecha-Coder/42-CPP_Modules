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

typedef std::string str;
typedef unsigned int uint;

class ClapTrap 
{
    private:
        str name;
        uint hitPoint;
        uint energyPoint;
        uint attackDamage;

    public:
        ClapTrap();
        ClapTrap(str new_name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap &other);
        ~ClapTrap();
        
        void attack(const str& target);
        void takeDamage(uint amount);
        void beRepaired(uint amount);

        uint getHit() const;
        uint getEnergy() const;
        uint getAttack() const;
        str getName() const;

        void setHit(uint amount);
        void setEnergy(uint amount);
        void setAttack(uint amount);
        void setName(str name);
};

#endif