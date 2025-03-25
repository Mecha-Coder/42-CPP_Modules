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
