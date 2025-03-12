#include <iostream>
using std::string;
using std::cout;
/*
object-oriented -> represent entities better data (attributes), behaviour(methods) in our porgram
                -> the use of classes (building block of OOP) -> user-define datatype
                -> classes are not data, but a blueprint / model 
*/


/* 
- Access members of a class
- Members are private by default

Access Modifier - private, public & protected
private  : Not accessible outside the class, to be use within the class
public   : Can access anywhere
protected: Inbetween private & public (used for inheritance)

To access use dot "."
- obj.somevalue

type of member
- property / varaible / valie member - attribute
- function member - methods

Construction object | Initializing our object
- Using constructor -> special method -> invoke each time an object of a class is created
Rule
- constructor don't have a return type
- same name as the class
  

Type of constructor
- default constructor - if no constuctor is set compiler will called DC to assign default
  * string: is ""
  * int: garbage value
*/

/*
I/O stream
std::string expects a valid, null-terminated character array. If the pointer is NULL, it doesn't know where the string starts
*/

class Employee {
public:
    string Name;             // default: ""
    string Company;
    int Age;                // default: 0
    const char *Test;       // default: NULL -> when it is a NULL program crash
    char i;                  // default: '\0'
   
    void IntroduceYourself()
    {
        cout << "(str)  Name    :" << Name << "\n"
             << "(str)  Company :" << Company << "\n"
             << "(int)  Age     :" << Age << "\n"
             << "(char)  i      :" << (int)i << "\n";
    }

    Employee() {};
    Employee(string name, string company)
    {
        Name = name; Company = company; Age = 9; Test="test"; i = 'x';
    }
    Employee(string name, string company, int age)
    {
        Name = name; Company = company; Age = age; Test="test"; i = 'y';
    }
};


void example_1()
{
    Employee employee1;
    employee1.Name = "Saldina";
    employee1.Company = "YT-CodeBeauty";   // <---- this is how to access attribute
    employee1.Age = 25;
    employee1.IntroduceYourself();  // <----- and this is how to access methods

    cout << "\n***************************\n";

    Employee employee2; // <---- call the default constructor
    employee2.IntroduceYourself();
}

void example_2()
{
    Employee employee1("Saldina", "YH_Code");
    employee1.IntroduceYourself();

    cout << "\n***************************\n";

    Employee employee2("John", "Amazon", 35);
    employee2.IntroduceYourself();
}

int main()
{
   example_1();
   cout << "\n----------------------------------------------------------\n";
   example_2();
}


/*
- What is object oriented programming
- What are classes and object, how to use them - represent entities (attribute, method)
- Access modifiers - private, public & protected
- What are constructors and how to use it
*/