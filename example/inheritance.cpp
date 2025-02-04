#include <iostream>
using namespace std;

// Base class
class Animal 
{
    private:
        string name;
    public:
        Animal(string n) : name(n)
        {cout << "Base constructor called" << endl;}
       
        ~Animal()     {cout << "BYE Base" << endl;}         
        void eat()    {cout << name << " is eating food." << endl;}
        void sleep()  {cout << name << " is sleeping." << endl;}
        string getName() const {return name;}
};

// Derived class: Dog
class Dog : public Animal
{
    public:
        Dog(string n) : Animal(n)
        {cout << "Derived (Dog) constructor called" << endl;}
        
        ~Dog() {cout << "BYE Dog" << endl;}  
        void bark() {cout << getName() << " says Woof!" << endl;}
};

// Derived class: Cat
class Cat : public Animal
{
    public:
        Cat(string n) : Animal(n)
        {cout << "Derived (Cat) constructor called" << endl;}
        
        ~Cat() {cout << "BYE Cat" << endl;}  
        void meow() {cout << getName() << " says Meow!" << endl;}
};

int main()
{
    Dog dog("Buddy");
    Cat cat("Kitty");
    cout << "===================================" << endl;
    dog.eat();
    dog.sleep();
    dog.bark();
    cout << "===================================" << endl;
    cat.eat();
    cat.sleep();
    cat.meow();
    cout << "===================================" << endl;
}
