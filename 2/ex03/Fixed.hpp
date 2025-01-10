/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:20:56 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/09 13:20:56 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath> // for std::round

class Fixed
{
    private:
        int fix_point_num;
        static const int fractional_bits = 8; //int literal '8'
        
    public:
        Fixed();                               // Default constructor
        Fixed(const Fixed& other);             // Copy constructor
        Fixed(const int integer_num);          // Integer constructor
        Fixed(const float float_num);          // Float constructor
        Fixed& operator=(const Fixed& other);  // Copy assignment operator
        ~Fixed();                              // Destructor

        float toFloat(void) const;            // Convert to float
        int toInt(void) const;                // Convert to int
        
        int getRawBits(void) const;
        
        // Comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Increment/Decrement operators
        Fixed& operator++();    // Pre-increment
        Fixed operator++(int);  // Post-increment
        Fixed& operator--();    // Pre-decrement
        Fixed operator--(int);  // Post-decrement

        // Static min/max functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        // overloaded insertion operator (<<)
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};  

#endif