/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:05 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/08 19:19:05 by jpaul            ###   ########.fr       */
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
        
        Fixed();                              // Default constructor
        Fixed(const Fixed& other);            // Copy constructor
        Fixed(const int integer_num);         // Integer constructor
        Fixed(const float float_num);           // Float constructor
        Fixed& operator=(const Fixed& other); // Copy assignment operator
        ~Fixed();                             // Destructor

        float toFloat(void) const;            // Convert to float
        int toInt(void) const;                // Convert to int

        // overloaded insertion operator (<<)
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};  

#endif