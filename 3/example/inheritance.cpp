#include <iostream>
#include <string>

/*
  Derived class (child)
    - the class that inherits from another class
  
  Base class (parent)
    - the class being inherited from

  To inherit from a class, use the : symbol
  [class Car: public Vehicle]


  Multilevel Inheritance
    - Can also inherit from a derived class
*/


// Base class
class Vehicle 
{
  public:
    std::string brand = "Ford";
    void honk()  {std::cout << "Tuut, tuut!";}
};

// Derived class
class Car: public Vehicle 
{
  public:
    std::string model = "Mustang\n";
};

int main()
{
  Car myCar;
  myCar.honk();
  std::cout << myCar.brand + " " + myCar.model;
  return 0;
}
