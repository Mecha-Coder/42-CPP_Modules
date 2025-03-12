/* Lesson-05
- Constructor inheritance
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
    Base() {cout << "Base: Default constructor\n";}
    Base(int b) {cout << "Base: Parametric constructor = " << b << "\n";}
};

class Derived_1 : public Base
{ // Empty 
};

class Derived_2 : public Base
{
    public:
    Derived_2() {cout << "Derived_2: Default constructor\n";}
    Derived_2(int b) {cout << "Derived_2: Parametric constructor =" << b << "\n";}
};

class Derived_3 : public Base
{
    public:
    Derived_3() : Base()
    {cout << "Derived_3: Default constructor\n";}
    
    Derived_3(int b) : Base(b)
    {cout << "Derived_3: Parametric constructor = " << b << "\n";}

    Derived_3(int a, int b) : Base()
    {cout << "Derived_3: Parametric constructor = " << a << " " << b << "\n";}
};

int main()
{
    Derived_1 a;
    cout << "---------------------------\n\n";
    // Derived_1 b(6); // <--- Can't call parameterize constructor in base class
    cout << "---------------------------\n";
    Derived_2 c;
    cout << "---------------------------\n";
    Derived_2 d(8);

    // Always called default base class. So how invoke other constructor?
    cout << "\n\n\n";
    Derived_3 e;
    cout << "---------------------------\n";
    Derived_3 f(8);
    cout << "---------------------------\n";
    Derived_3 g(8, 10);
}
