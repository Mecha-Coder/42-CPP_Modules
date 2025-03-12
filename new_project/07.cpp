/* Lesson-07
- Abstract class
*/

#include <iostream>
#include <string>
using namespace std;

class Person { // <---- Now it is an abstract class
public:
    Person () {} // <--- no point putting here
    virtual void give() = 0;
};

class Boy : public Person {
public:
    void give() {cout << "Brown Bun\n";}
};

class Girl : public Person {
public:
    void give() {cout << "Pink Bun\n";}
};

int main()
{
    Boy b1;
    Girl g1;
    Person *ptr;
    //Person p1; //<--- can't instantialize

    ptr = &b1;
    ptr->give();

    ptr = &g1;
    ptr->give();
}