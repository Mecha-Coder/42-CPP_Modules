#include <iostream>
#include <map>  // <------- include this
#include <string>

/*
Note:
- Map is like dictionary in python
- store key value pair
- key must be unique, where as for value, can be the same
*/

void debug()   {std::cout << "This is debug function" << std::endl;}
void info()    {std::cout << "This is info function" << std::endl;}
void warning() {std::cout << "This is warning function" << std::endl;}
void error()   {std::cout << "This is error function" << std::endl;}

void complain(std::string issue)
{
    std::map<std::string, void (*)()> Action;
    Action["DEBUG"] = &debug;
    Action["INFO"] = &info;
    Action["WARNING"] = &warning;
    Action["ERROR"] = &error;

    // Check if the key exists
    if (Action.find(issue) != Action.end())
        Action[issue](); // Key exists, call the associated function
    else
        std::cout << "Invalid issue type: " << issue << std::endl;
}

int main()
{
    complain("WARNING");
    complain("fsdfdsf");
    complain("ERROR");
}
