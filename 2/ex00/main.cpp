/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:07 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/08 19:19:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;       // Default constructor called
    std::cout << "--------------------------------------------" << std::endl;
    Fixed b( a );  // Copy constructor called
    std::cout << "--------------------------------------------" << std::endl;
    Fixed c;       // Default constructor called
    std::cout << "--------------------------------------------" << std::endl;

    c = b; // Copy assignment operator called
    std::cout << "--------------------------------------------" << std::endl;

    std::cout << a.getRawBits() << std::endl;  // getRawBits member function called
    std::cout << b.getRawBits() << std::endl;  // getRawBits member function called
    std::cout << c.getRawBits() << std::endl;  // getRawBits member function called
    std::cout << "--------------------------------------------" << std::endl;

    a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;  // getRawBits member function 
    std::cout << "--------------------------------------------" << std::endl;
    return 0; // Destructor called
}

