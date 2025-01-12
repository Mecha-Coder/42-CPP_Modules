#include <iostream>

/*
    Grouping related 
    - classes 
    - function
    - variable
    under a specific name

Benefit: Organize code & prevent naming conflicts
*/

namespace MyMath
{
    int value = 10;
    int add(int a, int b)   {return (a + b);}
    int minus(int a, int b) {return (a - b);}

    void showValue() { std::cout << "Value is: " << value << std::endl;}
}

// :: scope resolution operator
int main()
{
    
    std::cout << "Add=" << MyMath::add(5, 3) << std::endl;
    std::cout << "Minus=" << MyMath::minus(5,3) << std::endl;
    std::cout << MyMath::value << std::endl;
    MyMath::showValue();
}
