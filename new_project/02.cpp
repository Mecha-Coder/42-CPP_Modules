/* Lesson-02:
- Default constructor
- Parametruc constructor
- Copy constructor
- Constructor overloading 
---> default parameter value (Default constructor + Parametruc constructor)
*/

#include <iostream>
#include <string>
using namespace std;

class Person {
    string Name;
    int Age;
    float Height;
public:

    // Person() { // <-- if not given, compiler will create its own default constructor
    //     Age = 0;
    //     Height = 0.0f;
    // }

    // Combine default and parametric constructor together
    Person(string name = "", int age = 0, float height = 0.0f) { // <-- constructor overloading
        Name = name;
        Age = age;
        Height = height;
    }

    Person(const Person &other) {
        Name = other.Name;
        Age = other.Age;
        Height = other.Height;
    }

    void getInfo() {
        cout << "Name  : " << Name << "\n"
             << "Age   : " << Age << "\n"
             << "Height: " << Height << "\n"
             << "\n\n";
    }
};

int main()
{
    Person p1; 
    p1.getInfo();

    Person p2("Jason", 30, 5.5f);
    p2.getInfo();

    Person p3(p2);
    p3.getInfo();

    Person p4 = p3; // <<-- this is also invoking copy constructor
    p4.getInfo();
}
