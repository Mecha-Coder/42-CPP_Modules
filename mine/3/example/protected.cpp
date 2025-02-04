#include <iostream>
#include <string>

/*
- "protect" access specifier
    - Can be access by inherited classes
*/

// Base class
class Employee 
{
  protected: // Protected access specifier
    int salary;
};

// Derived class
class Programmer: public Employee
{
  public:
    int bonus;
    
    void setSalary(int s) {salary = s;}
    int getSalary()       {return salary;}
};

int main()
{
    Programmer obj;
    obj.setSalary(5000);
    obj.bonus = 15000;
    std::cout << obj.getSalary() << std::endl;
    std::cout << "Bonus: " << obj.bonus << "\n";
}
