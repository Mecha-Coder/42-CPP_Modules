#include <iostream>

// Constructor & Destructor

/* --> Constructor
- Special member function in a class that automatically called
when an object of that class is created
- primary role is ot initalize tge data member of any object

Default Constructor: Take no argument
Parametetized Constructor: Take argumument
Copy Constructor: Create new object as a copy of existing object

Example
============
class MyClass 
{
    public:
        int x;
        MyClass() { x=0 }              // Default constructor
        MyClass(int value) { x=value } // Parameterized constructor
        MyClass(const MyClass& other)  // Copy constructor
        { x = other.x }
};
*/

class Rectangle {
public:
    double width, height;

    Rectangle() { // Default constructor
        width = 0.0;
        height = 0.0;
    }

    Rectangle(double w, double h) { // Parameterized constructor
        width = w;
        height = h;
    }
};

int main()
{
    Rectangle rect1;

    std::cout << rect1.width << " " << rect1.height << std::endl;

    Rectangle rect2(5.0, 7.5);

    std::cout << rect2.width << " " << rect2.height << std::endl;
}