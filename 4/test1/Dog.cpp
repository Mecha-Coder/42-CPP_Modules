#include "Dog.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Dog::Dog()
{
    type = "Dog";
    cout << "Dog: default constructor called\n";
}

Dog::~Dog() {cout << "Dog: destructed\n";}
        
//---------------------------------------------------------------------
// Methods

void Dog::makeSound() const {cout << "Dog: woof woof\n";}