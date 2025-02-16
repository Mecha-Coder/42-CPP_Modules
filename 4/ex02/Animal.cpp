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

Animal::~Animal() {std::cout << "Animal: destructed\n";}

//---------------------------------------------------------------------
// Methods

//void Animal::makeSound()const {std::cout << "Animal: no sound\n";}
str Animal::getType() const {return type;}
