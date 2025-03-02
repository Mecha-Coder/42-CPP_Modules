#include <iostream>
using std::string;
using std::cout;

/*
Inheritance

- base class | super class | parent class
- derived class | child class | sub class

How to inherit
==============
class derived_class : <access modifier> base_class    

protected - so that class that inherit it also can use 


Note: 
- every class will generate its own default constructor, 
but when we create our own contructor that default get erase

*/

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};


class Employee: AbstractEmployee
{
    string Company;
    int Age;
protected:
    string Name;
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

    string getName() {return (Name);}
    string getCompany() {return (Company);}
    int getAge() {return (Age);}

    void AskForPromotion()
    {
        if (Age > 30)   cout << Name << " get promotion\n";
        else            cout << Name << ", no promotion for you\n";
    }
};


class Developer : public Employee{
public:
    string PreferLingo;
    Developer(const char *name, const char *company, int age, const char *preferred_language)
    : Employee(name, company, age)
    {PreferLingo = preferred_language;}

    void FixBug()
    {
        cout << Name << " fixed bug using " << PreferLingo << "\n";
    }
};

class Teacher: public Employee {
public:
    string Subject;
  
    Teacher(const char *name, const char *company, int age, const char *subject)
    : Employee(name, company, age)
    {Subject = subject;}

    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << "lesson\n";
    }
};

int main()
{
    Developer d = Developer("Dalina", "MonkeyDDragon", 25, "C++");
    d.IntroduceYourself();
    d.FixBug();
    d.AskForPromotion();
    cout << "--------------------------------------\n";
    Teacher t = Teacher("Jerry", "CodeSSchool", 34, "CS50");
    t.IntroduceYourself();
    t.PrepareLesson();
    t.AskForPromotion();
}
