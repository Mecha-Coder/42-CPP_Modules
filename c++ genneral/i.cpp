#include <iostream>
#include <string>
using namespace std;

/*
- Type of constructor

Default constructor
======================
- c++ create own if not define
- But we also can overwrite it
- What it does -> initialize members with default value
- when create an intance of class -> assign default values to the attribute

About
1) Is like a function, name same as the class name
2) No return type
3) Does not receive parameters
5) Place in a public access member
6) C++ auto create it we do not define
7) Invoke automatically everytime create an object of a class


Parametric constructor
=====================
- can pass parameters

when we create our own constructor, the auto created default by c++ will get override
*/

class User {
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;

    User(){  // <------ default constructor, no parameters
        FirstName = "nn";
        LastName = "nln";
        Age = 0;
        Email = "nn@mail.com";
    }

    User(string fname, string lname, int age){
        FirstName = fname;
        LastName = lname;
        Age = age;
        Email = fname + "." + lname + "@mail.com";
    }

    void getInfo()
    {
        cout << "First : " << FirstName << "\n";
        cout << "Last  : " << LastName << "\n";
        cout << "Age   : " << Age << "\n";
        cout << "Email : " << Email << "\n";
        cout << "--------------------------------\n";
    }
};

ostream& operator<<(ostream &out, User &u)
{
    out << "First : " << u.FirstName << "\n";
    out << "Last  : " << u.LastName << "\n";
    out << "Age   : " << u.Age << "\n";
    out << "Email : " << u.Email << "\n";
    out << "--------------------------------\n";
    return (out);
}

int main()
{
    User u1;
    User u2("Jason", "Selau", 31);

    u1.getInfo();
    cout << u2;
}