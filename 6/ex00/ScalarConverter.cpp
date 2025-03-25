<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:52 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/25 20:52:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double nanDouble = numeric_limits<double>::quiet_NaN();
double posInfD = numeric_limits<double>::infinity();
double negInfD = numeric_limits<double>::infinity();

float nanFloat = numeric_limits<float>::quiet_NaN();
float posInfF = numeric_limits<float>::infinity();
float negInfF = numeric_limits<float>::infinity();

char C;
int I;
float F;
double D;

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

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

bool isSpecial(const string &s)
{
    string special[] = {"+inff", "inff", "-inff", "nanf", "+inf", "inf", "-inf", "nan"};

    for(int i=0; i < 8; i++)
    {
        if (s == special[i])
        {
            switch (i % 4)
            {
                case 0 : printOut(NULL, NULL, &posInfF, &posInfD); break;
                case 1 : printOut(NULL, NULL, &posInfF, &posInfD); break;
                case 2 : printOut(NULL, NULL, &negInfF, &negInfD); break;
                case 3 : printOut(NULL, NULL, &nanFloat, &nanDouble); break;
            }
            return true;
        }
    }
    return false;
}

bool isChar(const string &s)
{
    if (s.size() == 1 && !isdigit(s[0]))
    {
        C = static_cast<char>(s[0]);
        I = static_cast<int>(s[0]);
        F = static_cast<float>(s[0]);
        D = static_cast<double>(s[0]);
        printOut(&C, &I, &F, &D);
        return true;
    }
    return false; 
}

bool isNumber(string &s)
{
    if ()
}

void ScalarConverter::convert(string s)
{
    if (!isChar(s) && !isSpecial(s) && isNumber(s))
        printOut(NULL, NULL, NULL, NULL);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:52 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/24 13:56:51 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

/*
Message
char is not printable -> "non displayable char"
invalid convertion    -> "conversion not possible"
*/
class ScalarConverter
{
    ScalarConverter() {cout << "ScalarConverter: Default CT called\n";}
    ~ScalarConverter(){cout << "ScalarConverter: Destroy\n";}

public:
    static void convert(const string &s)
    {
        std::cout << "Converting: " << s << endl;
    }
};

int main(int ac, char **av)
{
    // ScalarConverter test; <--- Can't instantialize

    for (int i=1; i < ac; i++)
    {
        ScalarConverter::convert(av[i]);
        cout << "----------------------------\n";
    }
}

/* 
Test cases
==========

Input requirement
*****************
- Except for char parameters, only the decimal notation will be used.?

- Character literals (char) can be represented using single quotes ('c', 'A', etc.).

- Other numeric types (int, float, double) will always be provided in decimal format and not in other bases like hexadecimal (0x2A) or octal (052)

Valid inputs
***************************************
./convert 'a' 'c' 'A' '@'
./convert 0 -1 42 -42 6289
./convert 2147483647 2147483999
./convert –2147483648 –2147483999
./convert 3.14 2.71
./convert 0.0f -4.2f 4.2f 42.0f
./convert -inff, +inff, nanf
./convert -inf, +inf and nan
./convert 0.0, -4.2, 4.2


Invalid inputs
****************************************
./convert
./convert "Hello there"
./convert 0x2A
./convert 052

✅ Handles char, int, float, and double conversions correctly
✅ Detects invalid conversions and prints meaningful error messages
✅ Prevents instantiation by making the constructor private
✅ Handles -inf, +inf, nan, -inff, +inff, nanf properly
✅ Handles edge cases like out-of-range integers

char 0<  >255

int -2,147,483,648 to 2,147,483,647 

float
1.2×10 −38 =0.000000000000000000000000000000000000012
3.4×10 38  =340,000,000,000,000,000,000,000,000,000,000,000,000

*/
>>>>>>> baa013ccf69e42b7565b440b515c731f4b9c822b
