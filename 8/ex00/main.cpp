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
    std::vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);

    std::list<int> arr2;
    arr2.push_back(1);
    arr2.push_back(64);
    arr2.push_back(-3);
    arr2.push_back(7);

    if (easyfind(arr1, 3))  std::cout << "Found" << std::endl;
    else                    std::cout << "Not found!" << std::endl;

    if (easyfind(arr1, 10)) std::cout << "Found" << std::endl;
    else                    std::cout << "Not found!" << std::endl;

    if (easyfind(arr2, -3)) std::cout << "Found" << std::endl;
    else                     std::cout << "Not found!" << std::endl;
}