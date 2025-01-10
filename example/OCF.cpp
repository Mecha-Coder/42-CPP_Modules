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
#include <iostream>
#include <cstring> // For strcpy and strlen

class MyClass
{
    private:
        char* data;

    public:
        MyClass() : data(NULL) {std::cout << "Default constructor called\n";}

        MyClass(const char* str)
        {
            std::cout << "Parameterized constructor called\n";
            if (str)
            {
                data = new char[strlen(str) + 1];
                strcpy(data, str);
            } 
            else 
                data = NULL;
        }
    
        MyClass(const MyClass& other)
        {
            std::cout << "Copy constructor called\n";
            if (other.data)
            {
                data = new char[strlen(other.data) + 1];
                strcpy(data, other.data);
            } 
            else
                data = NULL;
        }
    
        MyClass& operator=(const MyClass& other)
        {
            std::cout << "Copy assignment operator called\n";
            if (this != &other) // Avoid self-assignment
            {   
                delete[] data; // Free existing resource
                if (other.data) // Copy resource from other
                {
                    data = new char[strlen(other.data) + 1];
                    strcpy(data, other.data);
                }
            }
            else
                data = NULL;
            return *this;
        }

        ~MyClass() 
        {
            std::cout << "Destructor called\n";
            delete[] data; // Free allocated memory
        }

        // Method to display the data
        void display() const 
        {
            if (data) std::cout << "Data: " << data << std::endl;
            else std::cout << "Data: NULL" << std::endl;
        }
};

int main()
{
    // Calls parameterized constructor
    MyClass obj1("Hello, world!");
    obj1.display();
    std::cout << "\n====================================\n" << std::endl; 


    // Calls copy constructor 
    MyClass obj2 = obj1;
    obj2.display();
    std::cout << "\n====================================\n" << std::endl; 


    // Calls default constructor
    MyClass obj3;
    obj3.display();
    std::cout << "\n====================================\n" << std::endl;


    // Calls copy assignment operator
    obj3 = obj1;
    obj3.display();
    std::cout << "\n====================================\n" << std::endl; 

    std::cout << "Destructor will be called for all objects" << std::endl;
    return 0;
}
