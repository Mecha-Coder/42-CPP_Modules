#include <iostream>
using std::string;
using std::cout;


/*
Abstraction
- hiding complex things behind a procedure to make it simple
- interface that hide the complex logic
- make interface using abstract classes

- implement a contract

What is any abstract class
- which class sign this contract need to provide the implementation
- force any class that sign to contract to implement

Abstract class (Contract)
===============
class AbstractClass
{
    virtual void AskForPromotion()= 0;      <---------- pure virtual function
}
*/


class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};



class Employee: AbstractEmployee
{
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

    void AskForPromotion()
    {
        if (Age > 30)   cout << Name << " get promotion\n";
        else            cout << Name << ", no promotion for you\n";
    }
};

int main()
{
    Employee employee1(NULL, "Blankrose", -200);
    Employee employee2 = Employee("John", "Intel", 40);
    employee1.IntroduceYourself();
    cout << "-------------------------------------------\n";
    employee2.IntroduceYourself();

    cout << "-------------------------------------------\n";
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}