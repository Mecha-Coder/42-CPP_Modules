/*
Pairs
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Normarl pair\n============" << endl; 
    pair<int, int> p = {1,3};
    cout << p.first << " " << p.second;
    cout << "\n\n";

    cout << "Nested pair\n============" << endl; 
    pair<int, pair<int,int>> q = {1,{3, 4}};
    cout << q.first << " " << q.second.second << " " << q.second.first;
    cout << "\n\n";

    cout << "Array of pairs\n============" << endl; 
    pair<int, int> array[] = {{3, 4}, {2,5} , {8,11}};
    for (auto pair: array) {
        cout << pair.first << " - " << pair.second << endl;
    }
}

