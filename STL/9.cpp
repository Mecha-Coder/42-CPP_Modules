/*
Recap vectors
*/

#include <vector>
#include <iostream>
using namespace std;

int main()
{   
    cout << "Creating vector\n==============\n";
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.push_back(50);
    for (auto num: v)
        cout << num << endl;
    cout << "Last value: " << v.back() << endl;
    cout << endl;


    cout << "Nested vector\n==============\n";
    vector<pair<int, int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(4,5); // <---interesting way to add
    for (auto pair: vec)
        cout << pair.first << " - " << pair.second << endl;
    cout << endl;
    
    cout << "Ways to assigned vector & using iterator\n=================================\n";
    vector<int> v0(5, 100);  // 5 times x 100
    vector<int> v1{5, 20};  // Init one sort
    vector<int> v2(v1);
   
    for (vector<int>::const_iterator i=v0.begin(); i != v0.end() ; i++)
        cout << *i << " ";
    cout << "\n-------------------------------\n";

    for (auto i=v1.begin(); i != v1.end() ; i++)
        cout << *i << " ";
    cout << "\n-------------------------------\n";

    for (auto i=v2.begin(); i != v2.end() ; i++)
        cout << *i << " ";
    cout << "\n-------------------------------\n";


    cout << "Delete data at this address\n========================\n";
    v2.erase(v2.begin() + 1);
    v2.erase(v2.begin());
    if (v2.empty()) cout << "Yes, I'm empty\n";
    cout << endl;


    cout << "Delete array of address\n=========================\n";
    v0.erase(v0.begin() + 2, v0.begin() + 4); // erase[start, end)
    for (auto num: v0)
        cout << num << " ";
    cout << endl;

    cout << "Insert\n=========================\n";
    vector<int> vv(2,199);
    vv.insert(vv.begin(), 300);
    vv.insert(vv.begin() + 1, 2, 10);
    for (auto num: vv)
        cout << num << " ";
    cout << endl;

}