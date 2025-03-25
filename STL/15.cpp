/*
Algorithm - 
for_each - start, end, function
count_if, 
all_of - return true if all meet condition


*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5};

    cout << "Before for each\n==============\n";
    for (auto num: v)
        cout << num << " " << endl;

    for_each(v.begin(), v.end(), [](int &x){x *= 3;});

    cout << "After for each\n==============\n";
    for (auto num: v)
        cout << num << " " << endl;

    cout << "\nCount  even\n==============\n";
    auto even = count_if(v.cbegin(), v.cend(), [](int x){return (x%2==0);});
    cout << "Number of even number = " << even << endl;

    cout << "\nCheck all meet this condition\n===================\n";
    auto check = all_of(v.cbegin(), v.cend(), [](int x){return (10 != x);});
    if (check)
        cout << "Yes, all is below 10"<< endl;
    else
        cout << "No, some are above 10"<< endl;
}

