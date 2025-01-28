#include <iostream>
#include <string>

/*
- class can also be derived from more than one base class
- comma-separated list
    [class NewClass: public ClassA, public ClassB]
*/

class ClassA
{
    public:
        void func_1() {std::cout << "This is Function A\n";}
};

class ClassB
{
    public: 
        void func_2() {std::cout << "This is Function B\n";}
};

class NewClass: public ClassA, public ClassB
{

};

int main()
{
    NewClass testing;

    testing.func_1();
    testing.func_2();
}