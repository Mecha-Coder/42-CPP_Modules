/*
Algorithm - find()
find(start, end, value)
find_if(start, end, condition)
search(start, end, pattern.start, pattern.end) -> looking for range
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

void example1() {
    vector<int> v{1,3,5,7,9};

    // can replace with auto
    vector<int>::iterator i = find(v.begin(), v.end(), 7);
    cout << *i << endl; 

    auto it = find(v.begin(), v.begin() + 2, 7);
    if (it == v.begin() + 2)
        cout << "match not found" << endl; 
}

void example2() {
    vector<int> v{1,3,5,7,9, 4};
    
    // auto is_even = [](int i){return (i % 2 == 0)
    auto result = find_if(v.begin(), v.end(), [](int i){return (i % 2 == 0);});

    if (result != v.end())
        cout << "Even number found :" << *result << endl;
    else
        cout << "Not even number found\n";
}

void example3()
{
    vector<int> v{1,3,5,7,9, 4};
    list<int> pattern{6,7,9};

    auto result = search(v.begin(), v.end(), pattern.begin(), pattern.end());
    if (result != v.end())
        cout << "Found sequence :" << *result << endl;
    else
        cout << "Sequence not found\n";
} 

int main()
{
    // example1();
    // example2();
    example3();
}

