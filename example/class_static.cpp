#include <iostream>

/*
    static attribute: 
        - shared among all objects
        (There's only one instance, regardless of how many objects created)
        - exits even no object class are created

        Defined outside the class
        int MyClass::count = 0;

        Access
        MyClass::count++;

    static method
        - Can be called without creating object
        - Cannot access none-static members
*/

/*
:: <- What actually used for

- Access global scope, like global variable
- Access static member of a class
- Access members of an enum
*/ 

// Static data member
class MyClass
{
    public:
        static int count;

    MyClass() {count++;}
};

// Static Member function
class MyCode
{
    public:
        static void staticFunction() 
        {std::cout << "Print me" << std::endl;}
};

int MyClass::count = 0; // Define outside of a class

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

    MyCode::staticFunction();  // Calling the static function directly
}