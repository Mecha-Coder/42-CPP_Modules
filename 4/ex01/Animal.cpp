/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:48:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 15:48:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Animal::Animal() :type("blank")  
{std::cout << "Animal: <" << type << "> default constructor called\n";}

Animal::Animal(const str& set_type)
{
    type = set_type;
	std::cout << "Animal: <" << type << "> parameterized constructor called\n";
}

Animal::Animal(const Animal& other)
{
    *this = other;
	std::cout << "Animal: Copy from" << other.type << "\n";
}

Animal& Animal::operator=(const Animal &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Animal: Assignment constructor called" << "\n";
    return (*this);
}

Animal::~Animal() {std::cout << "Animal: destructed\n";}

//---------------------------------------------------------------------
// Methods

void Animal::makeSound()const {std::cout << "Animal: no sound\n";}
str Animal::getType() const {return type;}
