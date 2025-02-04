/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:02 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/08 19:19:02 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 
If fractional_bits = 8,
To bit shift into fix-point number

number * scaling_factor
number * 2^8
    
2^8 = 256 (100000000 in binary)

*/
//============================================================================
Fixed::Fixed() : fix_point_num(0)
{std::cout << "Default constructor called" << std::endl;}

//============================================================================
Fixed::Fixed (const Fixed& other) : fix_point_num(other.fix_point_num)
{std::cout << "Copy constructor called" << std::endl;}

//============================================================================
Fixed::Fixed(const int integer_num)
{
    std::cout << "Int constructor called" << std::endl;
    fix_point_num = integer_num * (1 << fractional_bits);
}

//============================================================================
Fixed::Fixed(const float float_num)
{
    int scaler = 1 << fractional_bits;

    std::cout << "Float constructor called" << std::endl;
    fix_point_num = static_cast<int>(roundf(float_num * scaler));
}

//============================================================================
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Avoid self-assignment
        fix_point_num = other.fix_point_num;
    return *this;
}

//============================================================================
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//============================================================================
float Fixed::toFloat(void) const
{
    float holder;

    holder = static_cast<float>(fix_point_num) / (1 << fractional_bits);
    return (holder);
}

//============================================================================
int Fixed::toInt(void) const
{
    return (fix_point_num / (1 << fractional_bits));
}
//============================================================================
void Fixed::setRawBits(int const raw)
{fix_point_num = raw;}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fix_point_num);
}
/*
overloaded insertion operator (<<)
- allows objects of the Fixed class to be output directly using std::cout
(or other output streams)

- friend keyword: allows this function to access private or protected members
- std::ostream &out: A reference to an output stream (e.g., std::cout)

out << fixed.toFloat()

(e.g., std::cout << a << " " << b << std::endl;).
*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}