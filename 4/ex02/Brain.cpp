/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:19:02 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 18:19:02 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Brain::Brain()  
{std::cout << "Brain: default constructor called\n";}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; ++i) 
        ideas[i] = other.ideas[i];
	
    std::cout << "Brain: copy constructor called" << "\n";
}

Brain& Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain: assignment constructor called" << "\n";
    return (*this);
}

Brain::~Brain() {std::cout << "Brain: destructed\n";}

//---------------------------------------------------------------------
// Setter & Getter

void Brain::setIdea(int i, const str& idea) 
{
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}

str Brain::getIdea(int i) const 
{
    if (i >= 0 && i < 100)
        return ideas[i];
    return "";
}