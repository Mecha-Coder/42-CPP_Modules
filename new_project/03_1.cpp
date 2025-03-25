/* 
- Operator overloading (comparison)
*/
#include <iostream>
using namespace std;

class Person {
private: int Weight;
public:
    Person(int x=0) : Weight(x) {}

    bool operator>(const Person &other)
    {return Weight > other.Weight;}
};

int main()
{
    int w1, w2;

    cout << "Enter weight of Jon : ";
    cin >> w1;

    cout << "Enter weight of Rick : ";
    cin >> w2;

    Person Jon(w1), Rick(w2);

    if (Jon > Rick)
        cout << "Jon is heavier than Rick\n";
    else
        cout << "Rick is heavier than Jon\n";
}
