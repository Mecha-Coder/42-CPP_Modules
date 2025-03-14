#include <iostream>
#include <string>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
using namespace std;

/*
Write a program showing ATM functionality using OOP's
=====================================================
1) Check Balance - user can change balance in his account
2) Cash WithDraw - but invalid need to be valid withdraw < balance
3) User Details - check their details
4) Update Mobile No. - update mobile number
*/

bool isDigit(const string &num)
{
    for(char c : num)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

char getChar() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);          // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // Disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
    
    read(STDIN_FILENO, &ch, 1);              // Read a single character
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
    return ch;
}

class Account {
private:
    string Account ; 
    string Name; 
    string Phone;
    string Password;
    int Age ;  
    int Balance; 

public:
    void setAccount(string acc, string name, string phone, string pass, int age, int deposit)
    {
        Account = acc;
        Name = name;
        Phone = phone;
        Password = pass;
        Age = age;
        Balance = deposit;
    }

    bool login(string acc, string pass)
    {return (Account == acc && Password == pass);}

    void withdraw(int amount) 
    {
        if (amount > Balance || amount == 0)
            cout << "Invalid amount entered\n";
        else {
            Balance -= amount;
            cout << "Please take your cash withdrawal: " << amount << "\n"; 
        }
    }
    
    void updatePhone(string oldnum, string newnum)
    {
        if (Phone == oldnum && isDigit(newnum)) {
            Phone = newnum;
            cout << "Your new phone number was updated\n";
        }
        else {cout << "Encountered problem when updating phone detail\n";}
    }
    
    void checkBalance()
    {cout << "Your current balance is " << Balance << "\n";}
    
    void getInfo()
    {
        cout << "Account : " << Account << "\n"
             << "Name    : " << Name << "\n"
             << "Phone   : " << Phone << "\n"
             << "Age     : " << Age << "\n";
    }
};


int main()
{
    Account *accounts = new Account[3];
    accounts[0].setAccount("AC00501", "Jason S.K", "012-2667188", "123123", 45, 10000);
    accounts[1].setAccount("AC00B12", "Kenneth Lee", "019-1223333", "112233", 72, 50100);
    accounts[2].setAccount("AC01099", "Gerard Ramero", "016-9991199", "001122", 21, 240);

    while (true)
    {
        string acc, pass;
        bool status = false;

        system("clear");
        cout << "********* ATM MACHINE *********\n\n";
        
        if (status)
        {

        }
        else
        {
            cout << "Please enter your account : ";
            getline(cin, acc);
            cout << "\nPlease enter PIN : ";
            getline(cin, pass);

            for (int i = 0; i < 3 ; i++)
            {
                if (accounts[i].)
                {
                    status = true;
                    break;
                }
            }
        }
        
        cout << "\n\n" << acc << "   " << pass << "\n";
        getChar();
    }

    delete[] accounts;
}
