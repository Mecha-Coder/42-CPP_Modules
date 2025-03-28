/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:08:08 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 22:00:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <set>
#include <algorithm>

class Span {
    unsigned int N;
    std::set<int> arr;

    class StorageFullException : public std::exception 
    {public: 
        virtual const char *what() const throw()
        {return "Storage is full. Can't add anymore numbers\n";}
    };

    class FailToComputeException : public std::exception 
    {public: 
        virtual const char *what() const throw()
        {return "Fail to compute span\n";}
    };
    
public:
    Span (unsigned int n) : N(n) {}

    void addNumber(int x)
    {
        if (N >= arr.size())
            throw StorageFullException();
        arr.insert(x);
    }

    void shortestSpan()
    {
        if (arr.size() < 2)
            throw FailToComputeException();
      
    }

    void shortestSpan()
    {
        if (arr.size() < 2)
            throw FailToComputeException();

        arr.
    }
};