#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

using namespace std;

class Animal
{
    protected:
        string type;

    public:
        Animal();
        virtual ~Animal();
    
        virtual void makeSound() const;
        string getType() const;
};

#endif