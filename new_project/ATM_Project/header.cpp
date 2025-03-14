
#ifndef HEADER_CPP
#define HEADER_CPP 

#include <iostream>
#include <string>
#include <iomanip>  // For std::setw() and std::setfill()
#include <cctype>   // For std::isalpha
using namespace std;

/*
Write a program showing ATM functionality using OOP's
=====================================================
1) Check Balance - user can change balance in his account
2) Cash WithDraw - but invalid need to be valid withdraw < balance
3) User Details - check their details
4) Update Mobile No. - update mobile number
*/

class Account {
private:
    // Userdetail
    string Name; 
    int Age ; 
    string Phone;

    // Account detail
    static int Counter; // Auto created upon successful account creation
    string AccountNo ; 
    string Password ; 
    int Balance; 

public:
    Account(const string &name, int age, string &pass, int deposit, string phone);
    void checkBalance();
    void withdraw(int amount, string pass);
    void getInfo();
    void updatePhone(string phone); 
};

bool isDigit(const string &s);
bool isAlphabet(const string &s);
string padWithZero(int num);

#endif


