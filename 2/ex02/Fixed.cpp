/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:00:04 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/09 15:00:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//=============================================================================
// Constructors and Destructor

Fixed::Fixed() : fix_point_num(0) {}
Fixed::Fixed(const Fixed& other) : fix_point_num(other.fix_point_num) {}

Fixed::Fixed(const int integer_num) 
{fix_point_num = integer_num * (1 << fractional_bits);}

Fixed::Fixed(const float float_num) 
{fix_point_num = static_cast<int>(roundf(float_num * (1 << fractional_bits)));}

Fixed::~Fixed() {}

//=============================================================================
// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) 
{
    if (this != &other) {
        fix_point_num = other.fix_point_num;
    }
    return *this;
}

//=============================================================================
// Setters and getters

void Fixed::setRawBits(int const raw)
{fix_point_num = raw;}

int Fixed::getRawBits(void) const
{return (fix_point_num);}


//=============================================================================
// Conversion functions

float Fixed::toFloat(void) const 
{return static_cast<float>(fix_point_num) / (1 << fractional_bits);}

int Fixed::toInt(void) const 
{return fix_point_num / (1 << fractional_bits);}


//=============================================================================
// Comparison functions

bool Fixed::operator>(const Fixed& other) const 
{return fix_point_num > other.fix_point_num;}

bool Fixed::operator<(const Fixed& other) const
{return fix_point_num < other.fix_point_num;}

bool Fixed::operator>=(const Fixed& other) const
{return fix_point_num >= other.fix_point_num;}

bool Fixed::operator<=(const Fixed& other) const
{return fix_point_num <= other.fix_point_num;}

bool Fixed::operator==(const Fixed& other) const
{return fix_point_num == other.fix_point_num;}

bool Fixed::operator!=(const Fixed& other) const
{return fix_point_num != other.fix_point_num;}


//=============================================================================
// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const 
{
    Fixed result;
    result.fix_point_num = fix_point_num + other.fix_point_num;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.fix_point_num = fix_point_num - other.fix_point_num;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.fix_point_num = (fix_point_num * other.fix_point_num) / (1 << fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.fix_point_num == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result.fix_point_num = (fix_point_num * (1 << fractional_bits)) / other.fix_point_num;
    return result;
}

//=============================================================================
// Increment/Decrement operators

Fixed& Fixed::operator++() 
{
    ++fix_point_num;  // Directly modify the object's value
    return *this;
}

/*
Why (int) is required for post-increment:

++value vs value++
- The dummy parameter (int) is used to signal that it's the post-increment version (because there is no real parameter passed when calling value++ in code).
- It doesn't affect the logic but is required for distinguishing between the two versions of the operator.
*/

Fixed Fixed::operator++(int) 
{
    Fixed temp = *this; // Save current state
    ++(*this);          // Increment value
    return temp;        // Return the saved state
}

Fixed& Fixed::operator--() 
{
    --fix_point_num;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

//=============================================================================
// Static min/max functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {return (a < b) ? a : b;}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {return (a < b) ? a : b;}
Fixed& Fixed::max(Fixed& a, Fixed& b) {return (a > b) ? a : b;}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {return (a > b) ? a : b;}


//=============================================================================
// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}