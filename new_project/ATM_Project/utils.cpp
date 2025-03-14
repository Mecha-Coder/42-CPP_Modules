#include "header.cpp"

bool isDigit(const string &s)
{
    for (char c : s) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isAlphabet(const string &s)
{
    for (char c : s) {
        if (!isalpha(c))
            return false;
    }
    return true;
}

string padWithZero(int num)
{
    string s;

    s = to_string(num);
    if (s.length() < 8)
        s.insert(0, 8 - s.length(),'0');
    return s;
}