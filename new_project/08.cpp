/* Lesson-08
- Pointer in C++
*/

#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    int *ptr = &number;

    cout << "Address          | Value             \n";
    cout << "--------------------------------------\n";
    cout << &number << "   |  " << number << "\n";
    cout << &ptr    << "   |  " << ptr << "\n";  
}
