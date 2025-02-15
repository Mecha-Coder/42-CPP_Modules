#include "Cat.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Cat::Cat() : Animal("Cat")
{
    brain = new Brain;
    std::cout << "Cat: <" << type << "> default constructor called\n";
}

Cat::Cat(const Cat& other) : Animal("Cat")
{
    
    *this = other;
	std::cout << "Cat: Copy from" << other.type << "\n";
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        type = other.type;
        brain = other.brain;
    }
    std::cout << "Cat: Assignment constructor called" << "\n";
    return (*this);
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat: destructed\n";
}
        
//---------------------------------------------------------------------
// Methods

void Cat::makeSound() const {std::cout << "Cat: meow\n";}

//---------------------------------------------------------------------
// Setter & Getter

void Cat::setIdea(int i, const str &idea)
{ brain->setIdea(i, idea); }

str Cat::getIdea(int i) const
{return brain->getIdea(i);}