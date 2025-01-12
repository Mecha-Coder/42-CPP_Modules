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

#include "header.hpp"

int main(int ac, char **av) 
{
    if (ac != 4)
    {
        std::cerr
            << "\nError. Wrong input                         \n"
            << "==============================================\n"
            << "Example  >  ./replace  [filename]  [s1]  [s2] \n"
            << "                                              \n"
            << "filename > target file to copy                \n"
            << "      s1 > word to be replace with > s2       \n"
            << "      s2 > replacement word                   \n"
            << std::endl;
        return (1);
    }
    if (is_empty(av[1]) || is_empty(av[2]) || is_empty(av[3]))
    {
        std::cerr << ERR1 << std::endl;
        return 1;
    }
    if (run(av[1], av[2], av[3]))
        return 1;
    return 0;
}


bool is_empty(const std::string& s)
{
    int i = -1;
    while (s[++i])
    {
        if (!isspace(s[i]))
            return false;
    }
    return true;
}
