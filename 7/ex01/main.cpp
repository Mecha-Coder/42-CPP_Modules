/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:08:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 20:54:24 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int iArray[] = {1,2,3,4,5,6};
    std::string str = "Hello World";


    std::cout << YELLOW
    << "\nDoubling each element inside an int array"
    << "\n===========================================\n"
    << RESET;

    iter<int, int, void(int &)>(iArray, 6, double_value);

    for (int i=0; i < 6 ; i++)
        std::cout << iArray[i] << "\n";
    std::cout << "\n\n";

    std::cout << YELLOW
    << "\nPrinting each element with template function"
    << "\n============================================\n"
    << RESET;

    iter(str.c_str(), str.size(), printElement<char>);
    std::cout << "\n";
}
