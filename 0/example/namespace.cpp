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
    int add(int a, int b)   {return (a + b);}
    int minus(int a, int b) {return (a - b);}
}

// :: scope resolution operator
int main()
{
    //  printout |  "Add"  |  add(5,3) from Mymath   | printend 
    
    std::cout << "Add=" << MyMath::add(5, 3) << std::endl;

    // printout | "Minus"  |  minus(5,3) from Mymath | printend  

    std::cout << "Minus=" << MyMath::minus(5,3) << std::endl;
}
