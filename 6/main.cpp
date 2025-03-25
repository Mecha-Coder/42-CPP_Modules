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
