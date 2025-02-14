
#include "Dog.hpp"
#include "Cat.hpp"


/* Lesson learnt
- using the base pointer

- delete dog and cat with animal pointer
  only call the base class destructor
  add virtual

- function overriding
  - derived and base class having same method name
    add virtual
*/

int main()
{
    const Animal* meta = new Animal();
    cout << "-------------------------------------\n";
    const Animal* j = new Dog();
    cout << "-------------------------------------\n";
    const Animal* i = new Cat();
    cout << "-------------------------------------\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    cout << "-------------------------------------\n";
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    cout << "-------------------------------------\n";
    delete meta;
    cout << "-------------------------------------\n";
    delete j;
    cout << "-------------------------------------\n";
    delete i;
    return 0;
}
