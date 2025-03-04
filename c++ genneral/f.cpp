#include <iostream>
using namespace std;

/*
Relationship between Virtual Functions, Pure Virtual Function, Abstract Class

What is a Virtual Function
============================
- is a method(function) define in base_class and redefine in the derived_class

- inside the base_class create a function. A derived_class in inherit base_class and also create a function with the same name. So have 2 function implement at different class with the same name. Which one will the compiler select

- So what virtual function actual do is to execute the most derived function

- If we use to invoke that function using based class reference pointer, the most derived part will be executed

- the purpose of having virtual function is to give the ability of runtime polymorphism


Pure Virtual Function
========================
- based on the below example, it make sense of all instrument to make their respective sound. No need to implementaion in the based class. We just need to make sure the derived class implement this.abort

in based class we write a constract that this function derived class have to implement

syntax
*******
  virtual void MakeSound() = 0

* Forcing derived to implement this


So what is an abstract class
============================
- contain atleast 1 pure virtual function
*/

class Instrument {
public:
    virtual void MakeSound() = 0;
    // virtual void MakeSound() {
    //     cout << "Instrument is playing...\n";
    // }
};

class Accordion : public Instrument {
public:
    void MakeSound() {
        cout << "Accordion is playing...\n";
    }
};

class Piano : public Instrument {
public:
    void MakeSound() {
        cout << "Piano is playing...\n";
    }
};

int main()
{
    Instrument *i1 = new Accordion();
    // i1->MakeSound();
    Instrument *i2  = new Piano();
    // i2->MakeSound();

    Instrument *instrument[2] = {i1, i2};
    for(int i=0; i<2; i++)
        instrument[i]->MakeSound();
}
