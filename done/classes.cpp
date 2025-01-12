#include <iostream>

/*
    Blueprint (template) that encapsulate
        - attribute (list of variable like struct)
        - method (list of function)
    
    With that blueprint -> create objects (instance of class)

    Blueprint of a car
    ===================
    Attribute             object_1=Mike's_car   object_2=John's_car 
     - brand                     Honda                   BMW
     - color                      red                   black 
     - type                      sedan                   SUV
     - engine cc                 1.5cc                  1.8cc
    
    Method
     - forward()
     - reverse()
     - break()
     - horn()
*/

/* 
Classes have public, private & protected 
members(both attribute & method)
*****************************************
- Public members define the class's interface.

- Private members encapsulate the internal details of the class.

- Protected members allow controlled access between a base class and its derived classes.
*/
class Rectangle
{
    public: 
        double width;
        double height;
    
    double area()  {return (width * height);}
};  // remember to put semi-colon


int main()
{
    Rectangle rect;  // creata new variable with the datatpye: Ractangle 

    // To access the attribute or method 
    //  -> object_name.attribute
    //  -> object_name.method()
    
    // assign values
    rect.width = 5.23;
    rect.height = 3.41;

    std::cout << "Area of rectangle: " << rect.area() << std::endl;
}