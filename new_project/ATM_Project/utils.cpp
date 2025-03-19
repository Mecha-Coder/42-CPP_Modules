#include "header.hpp"

bool isDigit(const string &num)
{
    for(char c : num)
    {
        if (!isdigit(c) && c != '-')
            return false;
    }
    return true;
}

char getChar() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);          // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
    
    read(STDIN_FILENO, &ch, 1);              // Read a single character
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch;
}