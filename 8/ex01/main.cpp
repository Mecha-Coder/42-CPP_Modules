/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:08:08 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/28 21:15:04 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

class Span {
    unsigned int N;
    std::set<int> arr;

    class StorageFullException : public std::exception 
    {public: 
        virtual const char *what() const throw()
        {return "Can't add anymore numbers\n";}
    };

    class FailToComputeException : public std::exception 
    {public: 
        virtual const char *what() const throw()
        {return "Fail to compute span. Not enough numbers\n";}
    };
    
public:
    Span (unsigned int n)
    {
        if (n < 5)
            throw std::invalid_argument("Required at least 5");
        N = n;
    }

    void addNumber(int x)
    {
        if (arr.size() == N)
            throw StorageFullException();
        arr.insert(x);
    }

    template <typename T>
    void addNumber(T begin, T end)
    {
        if (arr.size() + std::distance(begin, end) == N)
            throw StorageFullException();
        arr.insert(begin, end);
    }

    

    int shortestSpan()
    {
        if (arr.size() < 2)
            throw FailToComputeException();
        
        int num = *arr.rbegin();
        int newNum;

        for(std::set<int>::iterator i = std::next(arr.begin()) ; i != arr.end(); i++)
        {
            newNum = *i - *std::prev(i, 1);
            if (num > newNum) 
                num = newNum;
        }
        return (num);
    }

    int longestSpan()
    {
        if (arr.size() < 2)
            throw FailToComputeException();
        return (*arr.rbegin() - *arr.begin()); 
    }
};