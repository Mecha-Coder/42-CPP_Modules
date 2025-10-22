/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:53:16 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 19:02:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef std::string str;

template <typename T>
class Array {
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


template <typename T>
void iterate(Array<T> &a)
{
    for (unsigned int i=0; i < a.getSize() ; i++)
        std::cout << a[i] << ", ";
    std::cout << "\n\n";
}

#include "Array.tpp"

#endif