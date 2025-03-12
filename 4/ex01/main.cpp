/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:03:46 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 20:23:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Cat.hpp"

/* Lesson learnt
- focuses on polymorphism, deep copying, memory management, and destructor order

- Problem to call setIdea and getIdea because not inside Animal Class
  add virtual telling the compiler it will be implemented in derived class

- copy of a Dog or a Cat mustn’t be shallow
- test that your copies are deep copies
*/

int main()
{
    const int size = 6;
    Animal* animals[size];
    
    for (int i = 0; i < size / 2; ++i)
    {
        animals[i] = new Dog();
        std::cout << "-------------------------------------\n";        
    }
    for (int i = size / 2; i < size; ++i)
    {
        animals[i] = new Cat();
        std::cout << "-------------------------------------\n"; 
    }

    std::cout << "\n\n";
    for (int i = 0; i < size; ++i)
        animals[i]->makeSound();
    std::cout << "-------------------------------------\n";
    
    animals[2]->setIdea(1, "Chase the rat");
    animals[3]->setIdea(1, "Chase the ball");

    for (int i = 0; i < size; ++i)
        std::cout << animals[i]->getType() << ": " << animals[i]->getIdea(1) << "\n";

    std::cout << "\n\n-------------------------------------\n";
    for (int i = 0; i < size; ++i)
    {    
        delete animals[i];
        std::cout << "-------------------------------------\n"; 
    }
}
