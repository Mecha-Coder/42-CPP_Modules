/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:03:46 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 16:03:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/* Lesson learnt
- using the base pointer

- delete dog and cat with animal pointer
  only call the base class destructor
  add virtual

- function overriding
  - derived and base class having same method name
    add virtual
*/

int main()
{
    cout << "Correct implementation\n\n";

    const Animal* meta = new Animal();
    std::cout << "-------------------------------------\n";
    const Animal* j = new Dog();
    cout << "-------------------------------------\n";
    const Animal* i = new Cat();
    const Animal* x(i);
    const Animal* y = j;

    cout << "-------------------------------------\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    cout << "-------------------------------------\n";

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    cout << "-------------------------------------\n";
    x->makeSound();
    y->makeSound();
    cout << "-------------------------------------\n";
    
    delete meta;
    cout << "-------------------------------------\n";
    delete j;
    cout << "-------------------------------------\n";
    delete i;
    
    cout << "\n\n\n\nIncorrect implementation\n\n";

    const WrongAnimal* beta = new WrongAnimal();
    cout << "-------------------------------------\n";
    const WrongAnimal* k = new WrongCat();
    cout << "-------------------------------------\n";
    std::cout << k->getType() << " " << std::endl;
    cout << "-------------------------------------\n";
    k->makeSound();
    beta->makeSound();   
    cout << "-------------------------------------\n";
    delete k;
    cout << "-------------------------------------\n";
    delete beta;
}
