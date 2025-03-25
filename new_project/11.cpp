/*
- this pointer
  - used inside the class
  - this is a pointer to the "calling object"
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
private: int age; string name;
public:
    Person(string name, int age)
    {
        this->age = age;
        this->name = name;
    }

    void getDetail()
    {
        cout << name << "\n";
        cout << age << "\n";
    }
};

int main()
{
    Person p1("Jason", 39);
    Person p2("Matthew", 15);

    p1.getDetail();
    cout << "---------------\n";
    p2.getDetail();
}