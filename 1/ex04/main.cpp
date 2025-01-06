/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:17:10 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 15:54:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file = "hello.txt";
    std::string output = file;
    size_t i = output.find('.');

    if (i!= std::string::npos) 
    {
        std::cout << "Character found at position: " << i << std::endl;
        output.insert(i, "_replace");
        std::cout << output << std::endl;
        
    } 
    else
        std::cout << "Character not found." << std::endl;

    return 0;
}
