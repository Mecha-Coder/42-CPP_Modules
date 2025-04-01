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

double nanDouble = std::numeric_limits<double>::quiet_NaN();
double posInfD = std::numeric_limits<double>::infinity();
double negInfD = -std::numeric_limits<double>::infinity();

float nanFloat = std::numeric_limits<float>::quiet_NaN();
float posInfF = std::numeric_limits<float>::infinity();
float negInfF = -std::numeric_limits<float>::infinity();

double intMin = std::numeric_limits<int>::min();
double intMax = std::numeric_limits<int>::max();

char C;
int I;
float F;
double D;

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &original){(void)original;}

void printOut(char *a, int *b, float *c, double *d)
{
    if (a && *a) std::cout << "char  : '" << *a << "'\n";
    else if (a)  std::cout << "char  : non_displayable\n";
    else         std::cout << "char  : impossible\n";

    if (b) std::cout << "int   : " << *b << "\n";
    else   std::cout << "int   : impossible\n";
    if (c) std::cout << "float : " << std::fixed << std::setprecision(5) << *c << "f\n";
    else   std::cout << "float : impossible\n";
    if (d) std::cout << "double: " << std::fixed << std::setprecision(15) << *d << "\n";
    else   std::cout << "double: impossible\n";
}

bool isSpecial(const str &s)
{                      //0                               0
    str special[] = {"+inff", "inff", "-inff", "nanf", "+inf", "inf", "-inf", "nan"};

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

bool isChar(const str &s)
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

bool isNumber(str &s)
{
    size_t i = 0;
    int count = 0;
    double num;
    char *balance;

    // remove 'f' from 0.00f
    if (s[s.size() - 1] == 'f')
        s.erase(s.size() -1);
    
    // Skip character[0] if is a signage
    if (s[0] == '-' || s[0] == '+')
        i = 1;

    // Check only contain digit or only 1 dot (.)
    while (i < s.size())
    {
        if (!isdigit(s[i]) && s[i] != '.')
            return false; 
        if ((s[i] == '.') && (++count == 2))
            return false;
        i++;
    }

    // Check if convert successful & within limit 
    num = strtod(s.c_str(), &balance);
    if (*balance != '\0' || num > intMax || num < intMin)
        return (false);

    I = static_cast<int>(num);
    F = static_cast<float>(num);
    D = num;

    if (num >= 32.0 && num <= 126.0)
        C = static_cast<char>(num);
    else if (num >= 0.0 && num <= 255.0)
        C = '\0';
    else 
    {
        printOut(NULL, &I, &F, &D);
        return true;
    }
    printOut(&C, &I, &F, &D);
    return true;
}

void ScalarConverter::convert(str s)
{     // ASCII 32 -126 'a' '~' '1'
    if (!isChar(s) && !isSpecial(s) && !isNumber(s))
        printOut(NULL, NULL, NULL, NULL);
}
