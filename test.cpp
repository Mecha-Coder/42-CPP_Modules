#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 1800-05-32  2009-01-02,0
int main()
{
    map<string, int> a;
    a["Monday"] = 5;
    a["Tuesday"] = 6;
    a["Wednesday"] = 7;

    map<string, int>::iterator start = a.begin();
    map<string, int>::iterator end = a.end();

    cout << (end == a.end()? "Yes": "No") << "\n";
    cout << (start == a.begin()? "Yes": "No") << "\n";
    ++end;
    cout << (end == a.end()? "Yes": "No") << "\n";

    --start;
    cout << (start == a.begin()? "Yes": "No") << "\n";
    cout << (start == a.end()? "Yes": "No") << "\n";

    /*
    string first = "2009-01-02";
    string date = "1800-05-32";

    cout << (first > date? "Yes": "No") << "\n";
    */
}