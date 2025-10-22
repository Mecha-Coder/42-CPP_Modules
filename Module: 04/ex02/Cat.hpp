#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat &other);
        ~Cat();

        Animal&	operator=(const Animal& other);
        void makeSound() const;
        void setIdea(int i, const str &idea);
        str getIdea(int i) const;
};

#endif