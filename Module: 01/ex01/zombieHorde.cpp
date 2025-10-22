/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:10:25 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 10:31:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N]; 
    
    for (int i = 0; i < N; i++)
        horde[i] = Zombie(name);

    std::cout << "\n================================" << std::endl;
    
    return (horde);
}