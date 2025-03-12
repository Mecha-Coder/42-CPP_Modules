/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:03:24 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 16:03:24 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

WrongAnimal::WrongAnimal() :type("blank")  
{cout << "WrongAni: <" << type << "> default constructor called\n";}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
	std::cout << "WrongAni: Copy from" << other.type << "\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "WrongAni: Assignment constructor called" << "\n";
    return (*this);
}

WrongAnimal::~WrongAnimal() {cout << "WrongAni: destructed\n";}

//---------------------------------------------------------------------
// Methods

void WrongAnimal::makeSound()const {cout << "WrongAni: no sound\n";}
string WrongAnimal::getType() const {return type;}
