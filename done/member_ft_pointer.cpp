#include <iostream>

class MyClass
{
	public:
    	void show(int num) {
        	std::cout << "Number: " << num << std::endl;
        }
};

void func(MyClass obj, void (MyClass::*funcPtr)(int))
{
    (obj.*funcPtr)(88);
}

int main() {
    MyClass obj;

    void (MyClass::*funcPtr)(int) = &MyClass::show;

    (obj.*funcPtr)(42);
    func(obj, funcPtr);
}