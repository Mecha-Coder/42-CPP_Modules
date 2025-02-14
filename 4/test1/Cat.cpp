#include "Cat.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Cat::Cat()
{
    type = "Cat";
    cout << "Cat: default constructor called\n";
}

Cat::~Cat() {cout << "Cat: destructed\n";}
        
//---------------------------------------------------------------------
// Methods

void Cat::makeSound() const {cout << "Cat: meow\n";}