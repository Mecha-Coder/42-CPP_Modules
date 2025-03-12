/* Lesson-06
- Polymorphism
* Using base class pointer to call derived class methods
* virtual function
*/

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual void show() {cout << "This is base\n";}
    virtual void showme() {cout << "This is also base\n";}
};

class Derived_1 : public Base {
public:
    void show() {cout << "This is derived_1\n";}
};

class Derived_2 : public Base {
public:
    void show() {cout << "This is derived_2\n";}
};

class Derived_3 : public Derived_2 {
public:
    void show() {cout << "This is the most latest\n";}
};

// ==========================================================

int main()
{
    Base *ptr;
    Derived_1 d1; 
    Derived_2 d2;
    Derived_3 d3;

    ptr = &d1;
    ptr->show();
    ptr->showme();
    cout << "-----------------------\n"; 
    ptr = &d2;
    ptr->show();
    ptr->showme();
    cout << "-----------------------\n";
    ptr = &d3;
    ptr->show();
    ptr->showme();
}
