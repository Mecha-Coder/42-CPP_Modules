/*
Container - vector 

Limitation of array - fixed size
vector vs dynamic array

auto = automatically assign type

- how to iterate vector
- other vector functionality
- add and remove at specific index
*/

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> numbers;

    for (int i=1; i <= 10; i++) {
        numbers.push_back(i);
    }

    // Iterate 1
    for (auto i = numbers.begin(); i !=numbers.end(); i++)
        cout << *i << endl;

    cout << "---------------------------------\n";
    // Iterate 2
    for (auto num: numbers)
        cout << num << endl;

    cout << "---------------------------------\n";
    // Iterate 3
    // cbegin cend >>> constant iterator
    for (auto i = numbers.cbegin(); i !=numbers.cend(); i++) {
       // *i = 20; <--- not able to modify the value
        cout << *i << endl;
    }

    cout << "---------------------------------\n";
    // Another way to traverse
    auto i = numbers.begin();
    cout << *(i + 5) << endl;

    cout << "---------------------------------\n";

    // Add and remove element at specific index
    // insert and erase keyword
    numbers.insert(numbers.begin() + 5, 88);
    numbers.erase(numbers.end() - 2);
    numbers.pop_back();
    for (auto num: numbers)
        cout << num << endl;

    cout << "===================================\n";
    cout << "vector functionality\n";
    cout << "===================================\n";
    
    cout << "Size :" <<  numbers.size() << endl;
    cout << "---------------------------------\n";
    cout << "Max size :" << numbers.max_size() << endl;
    cout << "---------------------------------\n";
    cout << "Capacity :" << numbers.capacity() << endl;
    cout << "---------------------------------\n";
    numbers.resize(5);
    cout << "After resize: " << numbers.size() << endl;
    cout << "---------------------------------\n";
    if (numbers.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is not empty\n";
    for (auto num: numbers)
        cout << num << endl;
    cout << "---------------------------------\n";
    cout << "Element [0] is: " << numbers[0] << endl;
    cout << "---------------------------------\n";
    cout << "Element at(0) is: " << numbers.at(0) << endl;
    cout << "---------------------------------\n";
    cout << "Front: " << numbers.front() << endl;
    cout << "---------------------------------\n";
    cout << "Back: " << numbers.back() << endl;
    cout << "---------------------------------\n";
    numbers.clear();
    if (numbers.empty())
        cout << "Vector is empty\n";
    else
        cout << "Vector is not empty\n";
    cout << "---------------------------------\n";
}