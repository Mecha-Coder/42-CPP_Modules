/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:08:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 18:10:32 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int iArray[] = {1,2,3,4,5,8};
    std::string str1 = "Hello World";
    std::string str2[] = {"Hello there", "Nice day to you", "Bye Bye"}; 

    //------------------------------------------------------------------

    std::cout << YELLOW << "\n\nInt type\n=========\n" RESET;

    iter<int, int, void(int &)>(iArray, 6, double_value);
    iter(iArray, 6, printElement<int>);


    //------------------------------------------------------------------

    std::cout << YELLOW << "\n\nChar type\n============\n" RESET;

    iter(str1.c_str(), str1.size(), printElement<char>);
    std::cout << "\n";

    //------------------------------------------------------------------

    
    std::cout << YELLOW << "\n\nC++ String type\n=================\n" RESET;

    iter(str2, 3, printElement<std::string>);
    std::cout << "\n\n";
}
