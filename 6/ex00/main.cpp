/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:52:01 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/25 18:09:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    // ScalarConverter a; // <---- Can't instantiate

    if (ac != 2 || !av[1][0]) 
    {
        std::cerr << "\n"
             << "Invalid argument\n"
             << "================\n"
             << "Expected: ./convert [value]\n\n";
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(av[1]);
}
