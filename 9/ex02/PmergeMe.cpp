/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:45 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 14:03:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool err_msg(Error code)
{
    std::cerr << RED "Error: " RESET;
    switch (code) 
    {
        case BAD_ARG: std::cerr << "Invalid argument. Expected => ./PmergeMe 3 5 9 7 4\n"; break;
        case NOT_NUM: std::cerr << "Invalid number found\n"; break;
        case NUM_OUT_RNG: std::cerr << "Number out of range (0 - INT_MAX)\n"; break;
    }
    return false;
}

void process_time(clock_t start, clock_t end, size_t size)
{
    double time =static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "\nSorting time for " << size << " elements is = " 
              << time << " us\n";
}

bool isNumber(const char *s)
{
    size_t size = strlen(s);
    size_t i = 0;
    
    if (s[0] == '-' || s[0] == '+') 
        i++;
    if ((size - i) < 1 || (size - i) > 10)
        return false;
    while (s[i] != '\0')
    {
        if (!isdigit(s[i++])) 
            return false;
    }
    return true;
}

void Ford_John_Sort(Deque &deq)
{
    Deque::iterator a = deq.begin();
    Deque::iterator b = deq.begin();
    b++;

    if (deq.size() == 1) return;
    if (deq.size() == 2) 
    {
        if (*a > *b)
        {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        return;
    }

    Deque large;
    Deque small;
    bool extra = false;

    while(true)
    {
        if (*a > *b) {large.push_back(*a); small.push_back(*b);}
        else         {large.push_back(*b); small.push_back(*a);}

        if (++a, ++b == deq.end()) break;
        if (++a, ++b == deq.end()) {extra = true; break;}
    }

    Ford_John_Sort(large);
    Ford_John_Sort(small);

    if (extra)
    {
        if (*a > large.front() && *a > small.back())
            large.push_back(*a);
        else 
            small.push_back(*a);
    }

    Deque::iterator lastcopy = std::copy(small.begin(), small.end(), deq.begin());
    std::copy(large.begin(), large.end(), lastcopy);
    
    Deque::iterator current = deq.begin();
    while (++current != deq.end())
    {
        int value = *current;
        a = current;
        b = current;

        while (a != deq.begin() && *(--a) > value)
            *(b--) = *a;
        
        if (value >= *a) *b = value;
        else             *a = value;
    }
}

void Ford_John_Sort(List &list)
{
    List::iterator a = list.begin();
    List::iterator b = list.begin();
    b++;

    if (list.size() == 1) return;
    if (list.size() == 2) 
    {
        if (*a > *b)
        {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        return;
    }

    List large;
    List small;
    bool extra = false;

    while(true)
    {
        if (*a > *b) {large.push_back(*a); small.push_back(*b);}
        else         {large.push_back(*b); small.push_back(*a);}

        if (++a, ++b == list.end()) break;
        if (++a, ++b == list.end()) {extra = true; break;}
    }

    Ford_John_Sort(large);
    Ford_John_Sort(small);

    if (extra)
    {
        if (*a > large.front() && *a > small.back())
            large.push_back(*a);
        else 
            small.push_back(*a);
    }

    List::iterator lastcopy = std::copy(small.begin(), small.end(), list.begin());
    std::copy(large.begin(), large.end(), lastcopy);
    
    List::iterator current = list.begin();
    while (++current != list.end())
    {
        int value = *current;
        a = current;
        b = current;

        while (a != list.begin() && *(--a) > value)
            *(b--) = *a;
        
        if (value >= *a) *b = value;
        else             *a = value;
    }
}

void Ford_John_Sort(Vector &vector)
{
    Vector::iterator a = vector.begin();
    Vector::iterator b = vector.begin();
    b++;

    // If 1 number, no need to sort
    // If 2 numbers, swap them if not sorted
    if (vector.size() == 1) return;
    if (vector.size() == 2) 
    {
        if (*a > *b)
        {
            int temp = *a;
            *a = *b;
            *b = temp;
        }
        return;
    }

    Vector large;
    Vector small;
    bool extra = false;

    // Compare pairs and group them into large and small container
    // At the last loop, determine with got extra, put it aside
    while(true)
    {
        if (*a > *b) {large.push_back(*a); small.push_back(*b);}
        else         {large.push_back(*b); small.push_back(*a);}

        if (++a, ++b == vector.end()) break;
        if (++a, ++b == vector.end()) {extra = true; break;}
    }

    // Recursively do the above until left 1 or 2 numbers
    Ford_John_Sort(large);
    Ford_John_Sort(small);

    // If got extra where to put it, large or small container
    if (extra)
    {
        if (*a > large.front() && *a > small.back())
            large.push_back(*a);
        else 
            small.push_back(*a);
    }

    // Merge the numbers back
    Vector::iterator lastcopy = std::copy(small.begin(), small.end(), vector.begin());
    std::copy(large.begin(), large.end(), lastcopy);
    
    // Perform normal insertion sort (speed same as binary insertion sort)
    Vector::iterator current = vector.begin();
    while (++current != vector.end())
    {
        int value = *current;
        a = current;
        b = current;

        while (a != vector.begin() && *(--a) > value)
            *(b--) = *a;
        
        if (value >= *a) *b = value;
        else             *a = value;
    }
}
