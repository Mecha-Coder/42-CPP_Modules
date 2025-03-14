/*
Write a program showing ATM functionality using OOP's
=====================================================
1) Check Balance - user can change balance in his account
2) Cash WithDraw - but invalid need to be valid withdraw < balance
3) User Details - check their details
4) Update Mobile No. - update mobile number
*/

#include "header.cpp"

void create_invalid_account()
{
    string name[] = {"", "This Name is Too Long!!!", "@ddsa567", "Else", "Else", "Else"};
    int age[]     = {20, 20, 20, 0, -12, 300};


    try {Account a();}
    catch (const exception &msg)
    {cerr << msg.what() << "\n";}
}

int main()
{
    create_invalid_account();
}