/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:08:08 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/28 21:15:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <climits>
#include <set>
#include <vector>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

class Span {
    unsigned int N;
    std::set<int> arr;

    class StorageFullException : public std::exception 
    {public: virtual const char *what() const throw();};

    class FailToComputeException : public std::exception 
    {public: virtual const char *what() const throw();};
    
    Span();
public:
    Span (long int n);
    Span(const Span &obj);
    Span &operator=(const Span &obj);

    void addNumber(int x);
    template <typename T> void addNumber(T begin, T end);
    
    int shortestSpan();
    int longestSpan();

    unsigned getMaxSize();
    void showNumbers();
};

template <typename T>
void Span::addNumber(T begin, T end) 
{
    if (arr.size() + std::distance(begin, end) > N)
        throw StorageFullException();
    arr.insert(begin, end);
}

#endif