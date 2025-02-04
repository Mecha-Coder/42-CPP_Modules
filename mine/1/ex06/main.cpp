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

int main(int ac, char **av) 
{
   if (ac != 2)
    {
        std::cerr 
            << "Incorrect input:\n"
            << "=====================\n"
            << "./harlFilter <level>\n"
            << "Level: <DEBUG><INFO><WARNING><ERROR><SWITCH>\n"
            << std::endl; 
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);
}