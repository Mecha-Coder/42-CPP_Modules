#include <iostream>
#include <cstddef>
#include <vector>
using namespace std;


void  Jacob_Sequence(std::vector<int> &seq, int len) 
{
    int a = 1, b = 1, now;

    if (len < 4) return;

    seq.push_back(1);
    seq.push_back(0);

    while (b <= len)
    {
        now = b + 2 * a;

        for (int j = now; j > b; j--)
        {
            if (j < len)
                seq.push_back(j);
        }
        a = b;
        b = now;
    }
}

void answer(int x)
{
    std::vector<int> seq;
    Jacob_Sequence(seq, x);

    cout << x << " => ";
    for (auto i = seq.begin(); i != seq.end(); i++)
        cout << *i << " ";
    cout << "\n\n";
}

int main()
{
    cout << "4 => "; answer(4);
    cout << "5 => "; answer(5);
    cout << "6 => "; answer(6);
    cout << "8 => "; answer(8);
    cout << "12 => "; answer(22);
    cout << "12 => "; answer(86);
}