#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
using namespace std;


bool isChar(const std::string &s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isInt(const std::string &s)
{
    for (size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

bool isFloat(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf") 
        return true;

    bool dot = false, f = false;
    for (size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (s[i] == 'f')
        {
            if (f || i != s.length() - 1) return false;
            f = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot && f;
}

bool isDouble(const std::string &s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;

    bool dot = false;
    for (size_t i = (s[0] == '-' || s[0] == '+') ? 1 : 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot;
}

void ScalarConverter::convert(const std::string &s)
{
    char c;
    int i;
    float f;
    double d;

    if (isChar(s))
    {
        c = s[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (isInt(s))
    {
        long l = std::atol(s.c_str());
        if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
        {
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
        }
        i = static_cast<int>(l);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (isFloat(s))
    {
        f = std::strtof(s.c_str(), NULL);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
        d = static_cast<double>(f);
    }
    else if (isDouble(s))
    {
        d = std::strtod(s.c_str(), NULL);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
        f = static_cast<float>(d);
    }
    else
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    // Print char conversion
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";

    // Print int conversion
    std::cout << "int: " << i << "\n";

    // Print float conversion
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f\n";

    // Print double conversion
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}
