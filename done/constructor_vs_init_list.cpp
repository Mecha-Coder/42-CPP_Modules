#include <iostream>

// Initialize with Constructor Body vs Initialize List

/* When to use
- const members must initialized in the init_list.
- Members without default constructors
- Improving performance: especially with complex objects.
*/
class MyClass_1 {
public:
    int data1; 
    std::string data2;

    MyClass_1(int d1, const std::string& d2) 
        : data1(d1), data2(d2) {} 
};

/* When to use
- simple assignments where efficiency concern.
- If initialization logic is complex and cannot be easily expressed in the initialization list.
*/
class MyClass_2 {
public:
    int data1;
    std::string data2;

    MyClass_2(int d1, const std::string& d2) { 
        data1 = d1; 
        data2 = d2; 
    }
};

int main() {
    MyClass_1 obj_1(10, "Hello"); 
    std::cout << obj_1.data1 << " " << obj_1.data2 << std::endl; 
   
   MyClass_2 obj_2(619, "Rey Mysterio");
   std::cout << obj_2.data1 << " " << obj_2.data2 << std::endl; 
}
