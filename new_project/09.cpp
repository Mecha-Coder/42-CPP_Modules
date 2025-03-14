/* Lesson-09
-  Virtual Destructor
*/

#include <iostream>
using namespace std;

class Base1 {
public: ~Base1() {cout << "Base1: Destroyed\n";}
};

class Base2 {
public: virtual ~Base2() {cout << "Base2: Destroyed\n";} // <--- virtual on destructor
};

class Derived1 : public Base1 {
public: ~Derived1() {cout << "Derived1: Destroyed\n";}
};

class Derived2 : public Base2 {
public: ~Derived2() {cout << "Derived2: Destroyed\n";}
};

int main()
{
    Base1 *b1 = new Derived1;
    delete b1;
    cout << "---------------------------------\n";
    Base2 *b2 = new Derived2; // <--- Destructor virtualize
    delete b2;

    /* Output
    ============
    Base1: Destroyed
    ---------------------------------
    Derived2: Destroyed
    Base2: Destroyed
    */
    
}

