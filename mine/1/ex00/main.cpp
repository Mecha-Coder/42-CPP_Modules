/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:41:20 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 09:55:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    // Allocate in heap. Can be use outside the function scope
    Zombie *heapZombie = newZombie("heap_Zombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n================================" << std::endl; 

    // Allocate in stack. Can't use outside the function
    randomChump("stack_zombie");
}