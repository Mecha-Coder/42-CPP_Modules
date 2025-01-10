/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:37 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/07 16:39:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() 
{
    Harl harl;

    std::cout << "Testing Harl's complaints at different levels\n" << std::endl;

    harl.complain("DEBUG");
    std::cout << "===================================\n" << std::endl;
    
    harl.complain("INFO");
    std::cout << "===================================\n" << std::endl;
    
    harl.complain("WARNING");
    std::cout << "===================================\n" << std::endl;
    
    harl.complain("ERROR");
    std::cout << "===================================\n" << std::endl;

    std::cout << "Testing with an unknown level:" << std::endl;
    harl.complain("UNKNOWN");
    
}