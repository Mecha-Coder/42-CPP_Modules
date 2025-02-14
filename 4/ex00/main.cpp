#include <iostream>

// Base class: Animal
class Animal {
protected:
    std::string type;

public:
    Animal() : type("Animal") {
        std::cout << "Animal constructor called\n";
    }

    virtual ~Animal() {
        std::cout << "Animal destructor called\n";
    }

    virtual void makeSound() const {
        std::cout << "Some generic animal sound\n";
    }

    std::string getType() const {
        return type;
    }
};

// Derived class: Dog
class Dog : public Animal {
public:
    Dog() {
        type = "Dog";
        std::cout << "Dog constructor called\n";
    }

    ~Dog() {
        std::cout << "Dog destructor called\n";
    }

    void makeSound() const override {
        std::cout << "Woof! Woof!\n";
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    Cat() {
        type = "Cat";
        std::cout << "Cat constructor called\n";
    }

    ~Cat() {
        std::cout << "Cat destructor called\n";
    }

    void makeSound() const override {
        std::cout << "Meow! Meow!\n";
    }
};

// WrongAnimal base class
class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal() : type("WrongAnimal") {
        std::cout << "WrongAnimal constructor called\n";
    }

    virtual ~WrongAnimal() {
        std::cout << "WrongAnimal destructor called\n";
    }

    void makeSound() const { // Note: This is NOT virtual
        std::cout << "Some generic wrong animal sound\n";
    }

    std::string getType() const {
        return type;
    }
};

// WrongCat derived class
class WrongCat : public WrongAnimal {
public:
    WrongCat() {
        type = "WrongCat";
        std::cout << "WrongCat constructor called\n";
    }

    ~WrongCat() {
        std::cout << "WrongCat destructor called\n";
    }

    void makeSound() const { // No override since WrongAnimal's makeSound is not virtual
        std::cout << "Meow?? (Wrong sound behavior)\n";
    }
};

// Main function for testing
int main() {
    std::cout << "----- Correct Animal Tests -----\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound(); // Will output the generic animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n----- Wrong Animal Tests -----\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound because it's not virtual

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
