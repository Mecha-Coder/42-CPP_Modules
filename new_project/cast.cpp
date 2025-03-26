#include <iostream>
using namespace std;

typedef struct s_data 
{
    int i;
} t_data;

class Base { public: virtual ~Base() {} };
class Derived : public Base {};

void example1()
{
    // reinterpret_cast (low level)
    // Unrelated pointer types (int* --> char*)
    // pointer to int (void* → uintptr_t)

    t_data data;
    void *pointer = reinterpret_cast<void *>(&data);
    t_data *revert = reinterpret_cast<struct s_data *>(pointer);

   cout << pointer << "  " << revert << "\n"; 

   char test = 'c';
   char *c = &test;
   int *i = reinterpret_cast<int *>(c);
   
   cout << *c << "  " << *i << "\n";
}

void printMessage(char* str) {
    cout << str << endl;
}

void example2()
{
    //Removes const
    const char* message = "Hello, world!";
    printMessage(const_cast<char*>(message)); 
}

void example3()
{
    // dynamic_cast() Downcasting (Derived ← Base) polymorphic classes
    // Returns nullptr (for pointers) or throws std::bad_cast (for references) on failure
    Base* basePtr = new Base();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        cout << "Downcast successful!" << std::endl;
    } else {
        cout << "Downcast failed, returned nullptr" << std::endl;
    }
}


int main()
{   
    example3();
}
