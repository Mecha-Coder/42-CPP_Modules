#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = -21898912.321987;
    float b = -21898912.321987;
    double c = -21898912.321987;

    cout << a << endl;
    cout << fixed << setprecision(5) << b  << endl; 
    cout << fixed << setprecision(15) << c  << endl;
}