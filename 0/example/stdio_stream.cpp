#include <iostream>

/* 
    stdio stream -> object to interact with 
    - stdin
    - stdout
    - stderr

    std::endl already inserts a newline and flushes the output buffer, there's no need for additional \n
*/

/*
    Question: 
    - input datatype is a string for cin?
    - how to print to strerr

Note: Notice the <<(out) (in)>> arrow direction
*/

void print_text(std::string input)
{
    std::cout << input << std::endl;
}

int main()
{
    int number;
    // char s[] = "Hello world"; Old way
    std::string s1 = "Hello ";
    std::string s2 = "World";
    std::string s = s1 + s2;

    std::cout << "Enter a number: ";
    std::cin >> number;       // <---auto convert with atoi

    std::cout << "You entered " << number << std::endl;
    std::cerr << "An error has occurred!\n" << std::endl;
    std::cout << s << std::endl;

    print_text("Yoyo");
}