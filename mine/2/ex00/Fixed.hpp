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

class Fixed
{
    private:
        int fix_point_num;
        static const int fractional_bits = 8; //int literal '8'
        
    public:
        
        Fixed();
        Fixed (const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        void setRawBits(int const raw);
        int getRawBits(void) const;

};

#endif