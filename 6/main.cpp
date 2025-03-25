<<<<<<< HEAD
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
using namespace std;

double nanDouble = numeric_limits<double>::quiet_NaN();
double posInfD = numeric_limits<double>::infinity();
double negInfD = numeric_limits<double>::infinity();

float nanFloat = numeric_limits<float>::quiet_NaN();
float posInfF = numeric_limits<float>::infinity();
float negInfF = numeric_limits<float>::infinity();


void printOut(char *a, int *b, float *c, double *d)
{
    if (a) cout << "char  : '" << *a << "'\n";
    else   cout << "char  : impossible\n";

    if (b) cout << "int   : " << *b << "\n";
    else   cout << "int   : impossible\n";

    if (c) cout << "float : " << fixed << setprecision(5) << *c << "f\n";
    else   cout << "float : impossible\n";

    if (d) cout << "double: " << fixed << setprecision(15) << *d << "\n";
    else   cout << "double: impossible\n";
}

/*
int main()
{
    char c = 'c';
    int i = -2147483648;
    float f = -2147483648.00501f;
    double d = 3648.0001;
    
    printOut(&c, &i, &f, &d);

    cout << "----------------------\n";

    printOut(NULL, NULL, NULL, NULL);

    cout << "----------------------\n";
    
    printOut(NULL, NULL, &nanFloat, &nanDouble);
}
*/

int main()
{
    char *endptr;
    string s = "-2147483999";
    cout << strtol(s.c_str(), &endptr, 10) << "\n"; 
    cout << strtof(s.c_str(), &endptr) << "\n";
    cout << strtod(s.c_str(), &endptr) << "\n";
}
=======
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
>>>>>>> baa013ccf69e42b7565b440b515c731f4b9c822b
