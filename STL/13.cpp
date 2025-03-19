/*
Type conversion - with class
*/

#include <iostream>
#include <string>
using namespace std;

class ClassA {
private: int x;
public: 
    ClassA(int i): x(i) {cout << "Conversion Constructor" << endl;}
    ~ClassA(){cout << "Destroy number " << x << endl;}

    operator string() 
    {
        cout << "Conversion Operator" << endl;
        return to_string(x);
    }
};

void example1()
{
    
    ClassA a(5);
    // string s1 = a;  <---- Not clear but still work
    // a = 10; <--- Not clear but still work
    // cout << s1 << endl; 

    string s2 = static_cast<string>(a);
    cout << "---------------------------------\n";
    a = static_cast<ClassA>(50);
}

void example2()
{
    int i = 10;
    void *v = static_cast<void*>(&i);
    int* p = static_cast<int*>(v);
    cout << v << " " << *p << endl;
}

class ClassB {
    private: int x;
    public:
        void f(int i) const {const_cast<ClassB*>(this)->x = i;}
        void printX() {cout << "x = " << x << endl;}
    };

void example3()
{
    ClassB a;
    a.printX();
    a.f(10);
    a.printX();
}

int main()
{
    cout << "\n1) Conversion operator / Conversion Constructor" << endl;
    example1();

    cout << "\n2) Converting to and for void" << endl;
    example2();

    // Dynamic conversion - determine during runtime
    // Use case -> Base class polymorphic (have virtual function)
    // Animal *bp1 = new Cat;
    // Animal *bp2 = new Dog;
    // Dog *PD = dynamic_cast<Dog *>(bp1) --> throw error
    // Dog *PD = dynamic_cast<Dog *>(bd2) --> OK

    cout << "\n4) Const_cast" << endl;
    example3();
}