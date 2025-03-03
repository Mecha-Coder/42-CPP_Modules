#include <iostream>
using std::cout; 
using std::string;

/*
std::string pass value can't be null
*/
void print(string s)
{
    cout << "print " << s << "\n";
}

int main()
{
    // print(NULL); program crash
    print("");
    print("Value");
}
