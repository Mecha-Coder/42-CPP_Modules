#include "Dog.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog: <" << type << "> default constructor called\n";
}

Dog::Dog(const Dog& other) : Animal()
{
    *this = other;
	std::cout << "Dog: Copy from" << other.type << "\n";
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Dog: Assignment constructor called" << "\n";
    return (*this);
}

Dog::~Dog() {std::cout << "Dog: destructed\n";}
        
//---------------------------------------------------------------------
// Methods

void Dog::makeSound() const {std::cout << "Dog: woof woof\n";}
