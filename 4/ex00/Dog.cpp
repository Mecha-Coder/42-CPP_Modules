/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:24:26 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/13 18:47:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

Dog::Dog() : Animal("Dog") 
{std::cout << "Dog: Default constructor called. No name assigned\n";}

Dog::Dog(str set_name) : Animal("Dog") , name(set_name)
{ std::cout << "Dog: " << name << " constructed!\n"; }

Dog::Dog(const Dog& other)
{
    *this = other;
	std::cout << "Dog: Copy from" << other.name << "\n";
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        name = other.name;
        type = other.type;
    }
    return (*this);
    
}

Dog::~Dog()
{ std::cout << "Dog: " << name  << " destructed!\n"; }

//------------------------------------------------------------------------
// Methods

void Dog::makeSound()
{std::cout << "Dog: " << name  << " bark...Woof Woof!\n";}