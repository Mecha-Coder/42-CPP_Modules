#include <iostream>
using std::string;
using std::cout;

/*
OPP Important concept

- Encapsulation
- Abstraction
- Inheritance 
- Polymorphism

Encapsulation
=============
- bundling data and method that work together within a class
- preventing outside of the class to interect and modify the data
- how to encapsulate - setters and getters
- benefit - setter have do input validation before setting the value
*/

class Employee
{
    // Set as private, can't access outside the class
    string Name;
    string Company;
    int Age;
public:
    Employee(const char *name, const char *company, int age)
    {setName(name); setCompany(company); setAge(age);}
    
    void IntroduceYourself()
    {
        cout << "Name   : " << Name << "\n"
             << "Company: " << Company << "\n"
             << "Age    : " << Age << "\n";
    }

    void setName(const char *name)
    {Name = (name && *name) ? name : "Unknown";}

    void setCompany(const char *company)
    {Company = (company && *company) ? company : "Unknown";}

    void setAge(int age)
    {Age = (age>=18 && age <= 100) ? age : 0;}
};

int main()
{
    Employee employee1(NULL, "Blankrose", -200);
    Employee employee2 = Employee("John", "Intel", 40);
    employee1.IntroduceYourself();
    cout << "-------------------------------------------\n";
    employee2.IntroduceYourself();
}
