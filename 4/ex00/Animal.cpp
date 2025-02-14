/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:27:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/13 18:36:11 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//------------------------------------------------------------------------
// Constructor & Destructor

Animal::Animal()
{std::cout << "Animal: Default constructor called\n";}

Animal::Animal(str set_type) : type(set_type)
{ std::cout << "Animal: " << type << " constructed!\n";}

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

Animal::~Animal()
{ std::cout << "Animal: " << type << " destructed!\n";}