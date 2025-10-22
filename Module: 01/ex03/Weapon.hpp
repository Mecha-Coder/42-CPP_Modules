/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:51:57 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 13:11:28 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string n) : type(n) {}
        ~Weapon() {}

        const std::string& getType(void) const;
        void setType(std::string new_type);
};

#endif
