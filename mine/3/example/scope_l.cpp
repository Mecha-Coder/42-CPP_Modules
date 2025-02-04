#include <iostream>

class Base1
{
    public:
        void show() {std::cout << "Base1\n";}
};

class Base2
{
    public:
        void show() {std::cout << "Base2\n";}
};

class Myclass : public Base1, public Base2
{
    public:
        void show()
        {
            Base1::show();
            Base2::show();
        }
};


int main()
{
    Myclass test;
    test.show();
}