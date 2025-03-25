/*
Algorithm
- sort
- search
- count
- manipulate


sort(a, a+end) , where end is not included
exmaple: sort(v.begin(), v.end())

sort(start, end, comparator)


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_algo()
{
    vector<int> v{1,3,5,2};

    sort(v.begin(), v.end());
    for (auto num: v)
        cout << num << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for (auto num: v)
        cout << num << " ";
    cout << endl;
}

bool custom_comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    
    if (p1.first > p2.first) return true;
    return false;
}

void sort_custom_comparator() {
    pair<int, int> a[5] = {{1,2}, {3,1}, {4,1}, {3,4}, {3,1}};
    
    sort(a, a + 5, custom_comp);

    for (auto &p : a) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}


int main() 
{
    //sort_algo();
    sort_custom_comparator();
}
