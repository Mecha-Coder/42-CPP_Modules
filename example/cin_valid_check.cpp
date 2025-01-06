#include <iostream>
#include <limits> // std::numeric_limits<std::streamsize>::max()
#include <sstream>

int main() {
    int num;

    while (1) {
        std::cout << "Enter input: ";
        std::cin >> num;

        if (std::cin.fail()) 
        {
            std::cout << "Invalid number" << std::endl;
        
            std::cin.clear(); //Clear the fail error

            // Ignore remaining characters in the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        } 
        else
        {
            std::cout << num << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}
