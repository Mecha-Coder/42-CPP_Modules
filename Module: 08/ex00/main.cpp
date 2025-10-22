/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:29:49 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 21:03:21 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    std::list<int> b;
    b.push_back(1);
    b.push_back(64);
    b.push_back(-3);
    b.push_back(7);

    std::set<int> c;
    c.insert(-32);
    c.insert(52);
    c.insert(99);

    std::cout << YELLOW "\nVector Container\n===============\n" RESET
    << "Numbers: "; showNumber(a);
    std::cout << "3  : " << (easyfind(a, 3)?  "Found\n" : "Not found\n");
    std::cout << "10 : " << (easyfind(a, 10)?  "Found\n" : "Not found\n");
  

    std::cout << YELLOW "\nList Container\n===============\n" RESET
    << "Numbers: "; showNumber(b);
    std::cout << "-3  : " << (easyfind(b, -3)?  "Found\n" : "Not found\n");
    std::cout << "8 : " << (easyfind(b, 8)?  "Found\n" : "Not found\n");

    std::cout << YELLOW "\nSet Container\n===============\n" RESET
    << "Numbers: "; showNumber(c);
    std::cout << "99  : " << (easyfind(c, 99)?  "Found\n" : "Not found\n");
    std::cout << "90 : " << (easyfind(c, 90)?  "Found\n" : "Not found\n");

}