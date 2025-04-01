/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:15:54 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 13:15:54 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate()
{
    srand(time(0) ^ clock());
    int num = rand() % 3;
    
    if (num == 0) return (std::cout << "Created type A\n", new A);
    if (num == 1) return (std::cout << "Created type B\n", new B);
    if (num == 2) return (std::cout << "Created type C\n", new C);
    return (NULL);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))      std::cout << "1) What type = A\n";
    else if (dynamic_cast<B *>(p)) std::cout << "1) What type = B\n";
    else if (dynamic_cast<C *>(p)) std::cout << "1) What type = C\n";
}

void identify(Base &p)
{

    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "2) What type = A\n";
        return ;
    } catch(...){std::cout << "Failed A\n";}

    try {
        B b = dynamic_cast<B &>(p); 
        std::cout << "2) What type = B\n";
        return ;
    } catch(...){std::cout << "Failed B\n";}

    try {
        C c = dynamic_cast<C &>(p); 
        std::cout << "2) What type = C\n";
        return ;
    } catch(...){std::cout << "Failed C\n";}
}

int main()
{
    // dynamic cast 
    // Returns nullptr (for pointers) or throws std::bad_cast (for references) on failure
    // dynamic_cast() Downcasting (Derived ← Base) polymorphic
    
    Base *temp = generate();
    identify(temp); // "Identifying using pointer"
    identify(*temp); // "Identifying using reference"
    delete temp;
}
