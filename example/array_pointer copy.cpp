#include <string>
#include <iostream>
#include <limits>

void print_array(std::string info[], int size)
{
    int i = -1;

    while (++i < size)
        std::cout << info[i] << std::endl;
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
    int size = 5;
    std::string info[size];

    info[0] = "Hello";
    info[1] = "Hi";
    info[2] = "Nice";
    info[3] = "Day";
    info[4] = "More wordd 555";

    print_array(info, size);
    std::cout << "Done printing" << std::endl;
}