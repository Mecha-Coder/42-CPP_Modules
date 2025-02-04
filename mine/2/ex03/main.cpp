/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/09 15:18:28 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define RESET "\033[0m"

float calculateArea(Point const& p1, Point const& p2, Point const& p3) 
{
    return std::abs((p1.getX() * (p2.getY() - p3.getY()) +
                     p2.getX() * (p3.getY() - p1.getY()) +
                     p3.getX() * (p1.getY() - p2.getY())) / 2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    float totalArea = calculateArea(a, b, c);

    // Calculate the area of the sub-triangles formed with the point
    float a1 = calculateArea(point, b, c);
    float a2 = calculateArea(a, point, c);
    float a3 = calculateArea(a, b, point);

    return a1 > 0 && a2 > 0 && a3 > 0 && (a1 + a2 + a3) == totalArea;
}

int main(void) 
{
    Point a(1,3);
    Point b(-3, 1);
    Point c(2, -2);
    Point p(-1,1.5);

    std::cout << "Point(" << p.getX() << "," << p.getY() << ") --> ";

    if (bsp(a, b, c, p))
    {
        std::cout
            << GREEN << "Point is inside the triangle" << RESET 
            << std::endl;
    }
    else
    {
        std::cout
            << RED << "Sorry. Point is not inside the triangle" << RESET 
            <<std::endl;
    }
}
