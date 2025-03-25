/*
Generic programming - Template 
*/

#include <iostream>
using namespace std;

//=================================================================
// Template function
template <typename T>
T area(T a, T b)
{
    T answer = a*b;
    return (answer);
}
//=================================================================
// Template function with multiple time input
template <typename input1, typename input2, typename output>
output testing(input1 a, input2 b)
{
    cout << a << endl;
    cout << "Multiply number = " << b*b << endl;
    return (true); 
}
//=================================================================
// Template class
template <typename T>
class Calculator {
public:

    T add(T a, T b) {return (a + b);}

    T substract(T a, T b) {return (a - b);}
};
//=================================================================


int main()
{
    cout << area<int>(5, 5) << endl;
    cout << "------------------------------\n";
    cout << testing<string, int, bool>("Print me", 5) << endl;
    cout << "------------------------------\n";
    Calculator<int> intcal;
    cout << intcal.add(5.3, 5.9) << endl;
    cout << intcal.substract(5.3, 5.9) << endl;
    cout << "------------------------------\n";
    Calculator<float> floatcal;
    cout << floatcal.add(5.3, 5.9) << endl;
    cout << floatcal.substract(5.3, 5.9) << endl;
}
