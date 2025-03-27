/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:08:19 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 16:08:19 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void test()
{
    int* arr1 = new int[5];   // Uninitialized elements (garbage values)
    int* arr2 = new int[5](); // Zero-initialized elements

    std::cout << "arr1[0]: " << arr1[0] << std::endl; // Undefined (garbage)
    std::cout << "arr2[0]: " << arr2[0] << std::endl; // 0

    delete[] arr1;
    delete[] arr2;
}

int main()
{
    Array<int> *a1 = new Array<int>;
    std::cout << a1->getSize() << "\n";
    delete a1;
}
