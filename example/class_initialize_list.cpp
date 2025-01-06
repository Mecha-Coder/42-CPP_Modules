#include <iostream>

/*
    Initialization list -> initialize member during object creation;

    Example
    Myvalue object_name(value);
*/

// How to initialize more than 1...


class MyValue
{
    public:
        const int num;

    MyValue(int input) : num(input) {}
};

int main()
{
    MyValue dummy(10);
    std::cout << dummy.num << std::endl;
}