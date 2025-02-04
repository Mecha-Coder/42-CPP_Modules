/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:21:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 10:28:47 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
    int N = 5;

    Zombie *horde = zombieHorde(N, "Attack");

    for (int i = 0; i < N; ++i)
        horde[i].announce();
    std::cout << "\n================================" << std::endl; 
    delete[] horde;
}