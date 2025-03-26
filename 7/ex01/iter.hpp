/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:56:31 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 20:49:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

template <typename T1, typename T2, typename Func>
void iter(T1 *arr, T2 len, Func func)
{
    T2 i = 0;

    while (i < len)
    {
        func(arr[i]);
        i++;
    } 
}

// Simple function
void double_value(int &x)
{
    x *= 2;
} 

// Function template
template <typename T>
void printElement(T i)
{
    std::cout << i << ", ";
}

#endif
