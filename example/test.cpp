#include <iostream>
#include <string>

class MyClass
{
    private:
        int value;

    public:
        MyClass(int val) : value(val) {}
        int getValue() const { return value; }
};

// Overload the insertion operator
std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << obj.getValue(); // Use the public getter to access the value
    return os;            // Return the stream to allow chaining
}

int main() {
    MyClass obj(42);

    // Output the object using the overloaded << operator
    std::cout << "The value is: " << obj << std::endl;

    return 0;
}
