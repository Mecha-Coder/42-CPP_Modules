#include <iostream>
using namespace std;

class Base  {
public:
    virtual void print(ostream& os) const {os << "Base class";}
};

class Derived : public Base {
public:
    void print(std::ostream& os) const {os << "Derived class";}
};

ostream& operator<<(ostream& os, const Base& obj) 
{
    obj.print(os);
    return os;
}

int main() {
    Base b;
    Derived d;

    std::cout << b << std::endl;  // Output: Base class
    std::cout << d << std::endl;  // Output: Derived class (calls Derived::print)

    return 0;
}
