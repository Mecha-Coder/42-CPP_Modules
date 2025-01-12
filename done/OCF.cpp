// Orthodox Canonical Form (OCF)
// - guidelines for designing classes in C++

/*
Key Components of the OCF:
- Default Constructor
- Copy Constructor
- Copy Assignment Operator
- Destructor

class MyClass 
{
    public:
        MyClass() = default;              // Default constructor
        MyClass(const MyClass& other) { } // Copy constructor implementation 
        MyClass& operator=(const MyClass& other) { } // Copy assignment operator implementation
        ~MyClass() { }                    // Destructor implementation
};

1. Default Constructor
This constructor is responsible for initializing an object with default values.

2. Copy Constructor
The copy constructor is used to create a new object by copying an existing object.

3. Copy Assignment Operator
The copy assignment operator assigns the value of one object to another already existing object.

4. Destructor
The destructor is responsible for cleaning up any resources the class allocated when the object goes out of scope.
*/

#include <iostream>
#include <string>

class MyClass
{
    private:
        int data;

    public:
        MyClass() : data(0) {std::cout << "Default constructor called\n";}

        MyClass(int i) : data(i) {std::cout << "Parameterized constructor called\n";}

        MyClass(const MyClass& other) : data(other.data)
        { std::cout << "Copy constructor called\n";}
    
        MyClass& operator=(const MyClass& other)
        {
            std::cout << "Copy assignment operator called\n";
            if (this == &other) // Avoid self-assignment
                return *this;
            data = other.data;
            return *this;
        }

        ~MyClass() {std::cout << "Destructor called\n";}

        void display(std::string name) const 
        {std::cout << name << ": " << data << std::endl;}
};

int main()
{
    // Calls parameterized constructor
    MyClass obj1(5);       obj1.display("obj1");
    // Calls copy constructor 
    MyClass obj2 = obj1;   obj2.display("obj2");
    // Calls default constructor
    MyClass obj3;          obj3.display("obj3");
    // Calls copy assignment operator
    obj3 = obj1;
    obj3.display("obj3");
    std::cout << "Destructor will be called for all objects" << std::endl;
}
