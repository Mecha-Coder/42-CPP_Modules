#include <iostream>

/* 
    stdio stream -> object to interact with 
    - stdin
    - stdout
    - stderr
*/

/*
    Question: 
    - input datatype is a string for cin?
    - how to print to strerr

Note: Notice the << >> arrow direction
*/
int main()
{
    int number;
    char s[] = "Hello world";

    std::cout << "Enter a number: ";
    std::cin >> number;       // <---auto convert with atoi
    std::cout << "You entered " << number; 
    std::cout << "\n\n" << s << std::endl;
}