#include <iostream>
#include <map>
#include <string>

class MyClass
{
private:
    void func1() { std::cout << "This is func1" << std::endl; }
    void func2() { std::cout << "This is func2" << std::endl; }
    void func3() { std::cout << "This is func3" << std::endl; }

    std::map<std::string, void (MyClass::*)()> funcMap;

public:
    MyClass()
    {
        funcMap["func1"] = &MyClass::func1;
        funcMap["func2"] = &MyClass::func2;
        funcMap["func3"] = &MyClass::func3;
    }

    void select(std::string key)
    {
        typedef std::map<std::string, void (MyClass::*)()>::iterator FunctionMapIterator;
        FunctionMapIterator myIterator = funcMap.find(key);

        if (myIterator != funcMap.end()) // Check if key exists
        {
            (this->*(myIterator->second))(); // Call the function
        }
        else
        {
            std::cout << "Function not found." << std::endl;
        }
    }
};

int main()
{
    MyClass obj;
    obj.select("func2");
    obj.select("func10");
    obj.select("func3");
    obj.select("func1");
}


/*
Note 
=====
-  key(type)      value(type)
-     |                |
map<string, void (MyClass::*)()>

void (MyClass::*)() ---> pointer to a member function
funcMap.find(key)   ---> return iterator pointer to key-value pair or funcMap.end() if not found

this keyword --> is a pointer to the current instance of the class.
first : The key
second: The value
*/