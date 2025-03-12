#include "Cat.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat: <" << type << "> default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal()
{
    *this = other;
	std::cout << "Cat: Copy from" << other.type << "\n";
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
        type = other.type;
    std::cout << "Cat: Assignment constructor called" << "\n";
    return (*this);
}

Cat::~Cat() {std::cout << "Cat: destructed\n";}
        
//---------------------------------------------------------------------
// Methods

void Cat::makeSound() const {std::cout << "Cat: meow\n";}