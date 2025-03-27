/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:53:16 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 15:53:16 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    T *Arr;
    unsigned int Size;
public:
    Array();
    Array(unsigned int n);
    Array (const Array &obj);
    ~Array();

    Array &operator=(const Array &obj);
    T &operator[](unsigned int i);
    unsigned int getSize() const;
};

#include "Array.tpp"

#endif