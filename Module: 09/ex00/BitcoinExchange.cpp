/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:01:45 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/31 23:01:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool err_msg(Error code, str msg)
{
    std::cerr << RED "Error: " RESET;
    switch (code) 
    {
        case BAD_ARG: std::cerr << "Invalid argument. Expected => \"./btc input.txt\"\n"; break;
        case RD_FILE_FAIL: std::cerr << "Can't read file => " << msg << "\n"; break;
        case BAD_FORMAT: std::cerr << "Found data with invalid format => " << msg << "\n"; break;
        case BAD_INPUT: std::cerr << "Bad input => " << msg << "\n"; break;
        case BELOW_MIN: std::cerr << "Not a positive number\n"; break;
        case ABOVE_MAX: std::cerr << "Too large a number\n"; break;
        case NO_DATA: std::cerr << "No data for => " << msg << "\n"; break; 
    }
    return false;
}


str trim(const str &s) 
{
    size_t start = 0, end = s.size();

    while (start < end && isspace(s[start]))
        start++;
    while (end > start && isspace(s[end - 1]))
        end--;
    return s.substr(start, end - start);
}

/*
0123 4 56 7 89
2009 - 01 - 23
*/
bool isDate(const str &s)
{
    if (s.size() != 10) 
        return false;
    for (size_t i = 0; i < 10; ++i) 
    {
        if (i == 4 || i == 7)
        {
            if (s[i] != '-') return false;
        }
        else if (!isdigit(s[i])) 
            return false;
    }
    return true;
}


bool isValue(const str &s)
{
    size_t i = 0, dot = 0;
    
    if (!s[0])
        return false;
    if (s[0] == '-' || s[0] == '+') 
        ++i;
    while (i < s.size())
    {
        if (!isdigit(s[i]) && s[i] != '.')
            return false; 
        if ((s[i] == '.') && (++dot == 2))
            return false;
        i++;
    }
    return true;
}

/*
void check_date()
{
    std::cout << "\nOK\n==\n"
    << isDate("2090-00-55") << "\n"
    << isDate("2021-01-99") << "\n";

    std::cout << "\nKO\n==\n"
    << isDate("2134") << "\n"
    << isDate("1234-12-XX") << "\n"
    << isDate("1234-12-12-") << "\n"
    << isDate("2099.21.32") << "\n"
    << isDate("-1000") << "\n"
    << isDate("abc") << "\n"
    << isDate("    ") << "\n"
    << isDate("") << "\n";
}

void check_value()
{
    std::cout << "\nOK\n==\n"
    << isValue("0") << "\n"
    << isValue("-1") << "\n"
    << isValue("+1.") << "\n"
    << isValue(".001") << "\n"
    << isValue("+5.") << "\n"
    << isValue("23121.3213") << "\n";

    std::cout << "\nKO\n==\n"
    << isValue("+-1.") << "\n"
    << isValue("-1...") << "\n"
    << isValue("-1.0.") << "\n"
    << isValue("abc") << "\n"
    << isValue("    ") << "\n"
    << isValue("") << "\n";
}

void check_trim()
{
    std::cout
    << "[" << trim("  -213  ") << "]\n"
    << "[" << trim("-1") << "]\n"
    << "[" << trim("+1.    ") << "]\n"
    << "[" << trim("\t\t  --.001") << "]\n"
    << "[" << trim("     ") << "]\n"
    << "[" << trim("") << "]\n";
}

int main()
{
    std::cout << YELLOW "\nCheck Date\n===========\n\n" RESET;
    check_date();
    std::cout << YELLOW "\nCheck Value\n===========\n\n" RESET;
    check_value();
    std::cout << YELLOW "\nCheck Trim\n===========\n\n" RESET;
    check_trim();
}
*/
