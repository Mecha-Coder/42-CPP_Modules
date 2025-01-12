/*
Ad-hoc polymorphism: ability of functions or operators to behave differently based on their argument types

commonly implemented using 
- function overloading - same function name 
- operator overloading - change behaviour of user-define +,-,*
*/

#include <iostream>


double area(double radius)               {return 3.14159 * radius * radius; }
double area(double length, double width) { return length * width;}

void print(int value)       {std::cout << "Integer: " << value << std::endl;}
void print(double value)    {std::cout << "Double: " << value << std::endl;}
void print(const char* str) {std::cout << "String: " << str << std::endl;}

int main()
{
    // Example: Area Calculation
    std::cout << "Area of circle: " << area(5.0) << std::endl;
    std::cout << "Area of rectangle: " << area(3.0, 4.0) << std::endl; 

    // Example: Printing Values
    print(10);
    print(3.14);
    print("Hello, World!");
    return 0;
}
