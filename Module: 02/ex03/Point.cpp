/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:18 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/09 16:51:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)){}
Point::Point(const float _x, const float _y) : x(Fixed(_x)), y(Fixed(_y)) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}

Point& Point::operator=(const Point& other) 
{
    if (this != &other) 
    {
        // Since x and y are const, we cannot directly assign 
        // new values to them. 
        // We can't do: 
        // x = other.x; 
        // y = other.y; 

        // Since x and y are const, assignment isn't possible; throw error if misused
        std::cerr << "Assignment operator cannot modify const members" << std::endl;
    }
    return *this;
}

float Point::getX() const {return x.toFloat();}
float Point::getY() const {return y.toFloat();}

