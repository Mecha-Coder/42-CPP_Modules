/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:20:38 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/13 18:45:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    protected:
        str name;
    
    public:
        Dog();
        Dog(str set_name);
        Dog(const Dog& other);
        Dog& operator=(const Dog &other);
        ~Dog();

        void makeSound();
};

#endif