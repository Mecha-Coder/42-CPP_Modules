
#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
using namespace std;

class Account {
private:
    string Account ; 
    string Name; 
    string Phone;
    string Password;
    int Age ;  
    int Balance; 
public:
    void setAccount(string acc, string name, string phone, string pass, int age, int deposit);

    const string &getName() const;
    bool login(string acc, string pass);
    void withdraw();
    void updatePhone();
    void checkBalance();
    void getInfo();
};

bool isDigit(const string &num);
char getChar();
#endif
