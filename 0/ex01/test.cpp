#include <iostream>
#include <limits> // For std::numeric_limits<std::streamsize>::max()

int main() {
    int num;

    while (1) {
        std::cout << "Enter input: ";

        if (!(std::cin >> num)) 
        {
            std::cin.clear();

            // Ignore remaining characters in the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid number" << std::endl;
        } 
        else
            std::cout << num << std::endl;
    }
    return 0;
}
