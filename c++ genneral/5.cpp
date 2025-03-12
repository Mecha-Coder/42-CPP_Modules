#include <iostream>
using std::string;
using std::cout;


/*
Polymorphism - take many forms

ability of an object or method to take many forms

Usecase1: When a parent class reference used  to reference an object of a child class

The most common use of polymorphism is whne a parent class reference is used
to refer to a child class object

the use of virtual - check it there is an implemention in my derived classes
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

    virtual void Work()
    {
        cout << Name << " is checking backlog, email and some other stuff\n";
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

    void Work()
    {
        cout << Name << " is writing code\n";
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

    // void Work()
    // {
    //     cout << Name << " is teaching " << Subject << "\n";
    // }
};

int main()
{
    Developer d = Developer("Dalina", "MonkeyDDragon", 25, "C++");
    Teacher t = Teacher("Jerry", "CodeSSchool", 34, "CS50");
    d.Work();
    t.Work();

    cout << "---------------------------------\n"; 
    
    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
}