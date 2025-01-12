/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:34:35 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 10:49:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN"; //data

    std::string stringCOPY = str;  // New address with same data
    std::string *stringPTR = &str; // Point to the data's address
    std::string &stringREF = str;  // Store the data's address


    // Print memory address
    std::cout << &str << std::endl;
    std::cout << &stringCOPY << std::endl;
    std::cout << &stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    
    std::cout << "\n================================\n" << std::endl; 
    
    // Print value
    std::cout << str << std::endl;
    std::cout << stringCOPY << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}