#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#define nanDouble numeric_limits<double>::quiet_NaN()
#define posInfD numeric_limits<double>::infinity()
#define negInfD numeric_limits<double>::infinity()

#define nanFloat numeric_limits<float>::quiet_NaN()
#define posInfF numeric_limits<float>::infinity()
#define negInfF numeric_limits<float>::infinity()

#define intMin numeric_limits<int>::min()
#define intMax numeric_limits<int>::max()

#define floatMin numeric_limits<float>::min()
#define floatMax numeric_limits<float>::max()

#define doubleMin numeric_limits<double>::min()
#define doubleMax numeric_limits<double>::max()



int main()
{

    double input = 2147483999;
    
    char a   = static_cast<char>(input);
    int b    = static_cast<int>(input);
    float c  = static_cast<float>(input);
    double d = static_cast<double>(input);

    cout << fixed;

    // Print char representation
    /*if (isprint(a))
        cout << "char   : '" << a << "'\n";
    else
        cout << "char: Non displayable\n";*/

    // Print int, float, and double
    cout << "char   : '" << a << "'\n";
    cout << "int    : " << b << "\n";
    cout << "float  : " << fixed << c << "f\n";
    cout << "double : " << fixed << d << "\n\n\n";


    cout << nanDouble << "\n";
    cout << posInfD << "\n";
    cout << negInfD << "\n";
    cout << "---------------\n";
    cout << nanFloat << "\n";
    cout << posInfF << "\n";
    cout << negInfF << "\n";
    cout << "---------------\n";
    cout << intMin << "\n";
    cout << intMax << "\n";
    cout << "---------------\n";
    cout << floatMin << "\n";
    cout << floatMax << "\n";
    cout << "---------------\n";
    cout << doubleMin << "\n";
    cout << doubleMax << "\n";
}
