#include <iostream>

/*
    static attribute: 
        - shared among all objects
        - exits even no object class are created

    static method
        - Can be called without creating object
        - Cannot access none-static attribute
*/

// :: <- What actually used for

class MyClass
{
    public:
        static int count;

    MyClass() {count++;}
};

int MyClass::count = 0;

int main()
{
    std::cout << "\nobjects created = " << MyClass::count; 
    
    MyClass object1;
    std::cout << "\nobj1 = " << object1.count;

    MyClass object2;
    std::cout << "\nobj2 = " << object2.count;

    MyClass object3;
    std::cout << "\nobj3 = " << object3.count;

    std::cout << "\nobjects created = " << MyClass::count << std::endl; 
}