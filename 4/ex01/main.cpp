#include <iostream>
#include <cstring>

// Brain class
class Brain {
private:
    std::string ideas[100];

public:
    Brain() {
        std::cout << "Brain constructor called\n";
        for (int i = 0; i < 100; i++)
            ideas[i] = "Random Idea " + std::to_string(i);
    }

    Brain(const Brain& other) {
        std::cout << "Brain copy constructor called\n";
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }

    Brain& operator=(const Brain& other) {
        std::cout << "Brain assignment operator called\n";
        if (this != &other) {
            for (int i = 0; i < 100; i++)
                ideas[i] = other.ideas[i];
        }
        return *this;
    }

    ~Brain() {
        std::cout << "Brain destructor called\n";
    }
};

// Base class: Animal (Abstract Class)
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

    virtual void makeSound() const = 0;  // Pure virtual function

    std::string getType() const {
        return type;
    }
};

// Derived class: Dog
class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog() {
        type = "Dog";
        brain = new Brain();
        std::cout << "Dog constructor called\n";
    }

    Dog(const Dog& other) {
        std::cout << "Dog copy constructor called\n";
        brain = new Brain(*other.brain);  // Deep copy
        type = other.type;
    }

    Dog& operator=(const Dog& other) {
        std::cout << "Dog assignment operator called\n";
        if (this != &other) {
            delete brain;
            brain = new Brain(*other.brain);  // Deep copy
            type = other.type;
        }
        return *this;
    }

    void makeSound() const override {
        std::cout << "Woof! Woof!\n";
    }

    ~Dog() {
        delete brain;
        std::cout << "Dog destructor called\n";
    }
};

// Derived class: Cat
class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat() {
        type = "Cat";
        brain = new Brain();
        std::cout << "Cat constructor called\n";
    }

    Cat(const Cat& other) {
        std::cout << "Cat copy constructor called\n";
        brain = new Brain(*other.brain);  // Deep copy
        type = other.type;
    }

    Cat& operator=(const Cat& other) {
        std::cout << "Cat assignment operator called\n";
        if (this != &other) {
            delete brain;
            brain = new Brain(*other.brain);  // Deep copy
            type = other.type;
        }
        return *this;
    }

    void makeSound() const override {
        std::cout << "Meow! Meow!\n";
    }

    ~Cat() {
        delete brain;
        std::cout << "Cat destructor called\n";
    }
};

// Main function for testing
int main() {
    std::cout << "----- Individual Object Tests -----\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();

    delete j; // Should correctly call destructors
    delete i; // Should correctly call destructors

    std::cout << "\n----- Array of Animals (Half Dogs, Half Cats) -----\n";
    const int SIZE = 6;
    Animal* animals[SIZE];

    for (int k = 0; k < SIZE / 2; k++)
        animals[k] = new Dog();
    for (int k = SIZE / 2; k < SIZE; k++)
        animals[k] = new Cat();

    for (int k = 0; k < SIZE; k++)
        animals[k]->makeSound();

    for (int k = 0; k < SIZE; k++)
        delete animals[k];

    std::cout << "\n----- Testing Deep Copy -----\n";
    Dog originalDog;
    Dog copiedDog(originalDog);  // Copy constructor test
    Dog assignedDog;
    assignedDog = originalDog;  // Assignment operator test

    Cat originalCat;
    Cat copiedCat(originalCat);  // Copy constructor test
    Cat assignedCat;
    assignedCat = originalCat;  // Assignment operator test

    return 0;
}
