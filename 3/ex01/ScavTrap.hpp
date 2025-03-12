/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:33:25 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/28 16:13:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
    public:
        ScavTrap();
        ScavTrap(str name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap &other);
        ~ScavTrap();
   
        void attack(const str& target);
        void guardGate();
};

#endif
