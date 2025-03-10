#include <iostream>
#include <string>
using namespace std;

/*
Advanced Inheritance & Polymorphism
========================================
- Abstruct class can't create instance of that class
*/

class Monster {
public:
    virtual void attack() = 0;
    virtual ~Monster() {};
};

class Zombie : public Monster{
public:
    void attack() {cout << "Zombie bites";}
};

class Vampire : public Monster{
public:
    void attack() {cout << "Vampire suck blood";}
};

class Dragon : public Monster{
public:
    void attack() {cout << "Dragon breath fire";}
};

int main()
{
    Monster *m1 = new Zombie();
    Monster *m2 = new Vampire();
    Monster *m3 = new Dragon();

    m1->attack();
    m2->attack();
    m3->attack();

    delete m1;
    delete m2;
    delete m3;
}
