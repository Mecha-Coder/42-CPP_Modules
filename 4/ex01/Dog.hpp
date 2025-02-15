#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog &other);
        ~Dog();
    
        void makeSound() const;
        void setIdea(int i, const str &idea);
        str getIdea(int i) const;
};

#endif