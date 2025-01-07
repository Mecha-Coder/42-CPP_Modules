/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:36:37 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/07 16:28:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef enum e_complain
{
    WARNING
} t_complain;

int main(int ac , char **av) 
{
    if (ac != 2)
    {
        if (ac < 2)
            std::cerr << "Enter one of the 4 levels" << std::endl;
        else
            std::cerr << "Too many arguments" << std::endl;
        return (1);
    }

    Harl harl;
    harl.complain(av[1]);
}