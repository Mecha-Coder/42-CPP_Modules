/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:18:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/14 17:27:40 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout 
        << "==================================== " 
        << "Additional"
        << "==================================== "
        << std::endl;

    Fixed c(Fixed(3.625f));
    a = b - c;
    std::cout << a << std::endl;

    if (a > b)
        std::cout << "b is greater than a" << std::endl;
    else
        std::cout << "a is not greater than b" << std::endl;
    return 0;
}