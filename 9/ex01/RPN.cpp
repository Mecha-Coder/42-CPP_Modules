/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:19:10 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 05:19:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool err_msg(Error code)
{
    std::cerr << RED "Error: " RESET;
    switch (code) 
    {
        case BAD_ARG: std::cerr << "Invalid argument. Expected => ./RPN \"2 3 +\"\n"; break;
        case BAD_EXPRESS: std::cerr << "Only allowed numbers and operator: + - * /\n"; break; 
        case FAIL_COMPUTE: std::cerr << "Cannot compute\n"; break;
    }
    return EXIT_FAILURE;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*'|| c == '/');
}