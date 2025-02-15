/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:03:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 16:03:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

WrongCat::WrongCat()
{
    type = "Cat";
    cout << "WrongCat: <" << type << "> default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
    *this = other;
	std::cout << "WrongCat: Copy from" << other.type << "\n";
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "WrongCat: Assignment constructor called" << "\n";
    return (*this);
}

WrongCat::~WrongCat() {cout << "WrongCat: destructed\n";}
        
//---------------------------------------------------------------------
// Methods

void WrongCat::makeSound() const {cout << "WrongCat: meow\n";}