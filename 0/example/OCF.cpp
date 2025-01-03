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
        MyClass() = default; // Default constructor

        MyClass(const MyClass& other) { } // Copy constructor implementation 

        MyClass& operator=(const MyClass& other) { } // Copy assignment operator implementation

        ~MyClass() { } // Destructor implementation

        // ... other members ...
};
*/