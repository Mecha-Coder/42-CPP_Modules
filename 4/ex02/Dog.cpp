#include "Dog.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Dog::Dog()
{
    brain = new Brain;
    type = "Dog";
    std::cout << "Dog: <" << type << "> default constructor called\n";
}

Dog::Dog(const Dog& other)
{
    *this = other;
	std::cout << "Dog: Copy from" << other.type << "\n";
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        type = other.type;
        brain = other.brain;
    }
    std::cout << "Dog: Assignment constructor called" << "\n";
    return (*this);
}

Animal& Dog::operator=(const Animal &other)
{
    if (this != &other)
        type = other.getType();
    std::cout << "Animal: Assignment constructor called" << "\n";
    return (*this);
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Dog: destructed\n";
}
        
//---------------------------------------------------------------------
// Methods

void Dog::makeSound() const {std::cout << "Dog: woof woof\n";}

//---------------------------------------------------------------------
// Getter and Setter

void Dog::setIdea(int i, const str &idea)
{ brain->setIdea(i, idea); }

str Dog::getIdea(int i) const
{return brain->getIdea(i);}