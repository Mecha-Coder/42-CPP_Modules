/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:17:33 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/13 18:35:51 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Animal
{
    protected:
        str type;
    
    public:
        Animal();
        Animal(str set_type);
        Animal(const Animal& other);
        Animal& operator=(const Animal &other);
        ~Animal();
};

#endif