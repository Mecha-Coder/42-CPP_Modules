#include "header.hpp"
int login(Account *accounts, bool &status);
bool option(Account &acc);

int main()
{
    bool status = false;
    int i = 0;
    Account *accounts = new Account[3];
    accounts[0].setAccount("AC00501", "Jason S.K", "012-2667188", "123123", 45, 10000);
    accounts[1].setAccount("AC00B12", "Kenneth Lee", "019-1223333", "112233", 72, 50100);
    accounts[2].setAccount("AC01099", "Gerard Ramero", "016-9991199", "001122", 21, 240);

    while (true)
    {
        system("clear");
        cout << "********* ATM MACHINE *********\n\n";   
        if (status)
        {
            if (option(accounts[i]))
                break;
        }
        else
            i = login(accounts, status);
        getChar();
    }
    system("clear");
    cout << "Bye-bye\n";
    delete[] accounts;
}

/* 
login
======
- get use input 1) Account 2) PIN
- loop and check if there is a valid account and pin
- update &status reference to true if available
  * Return account index
- if no mathc print error
*/
int login(Account *accounts, bool &status)
{
    string acc, pass;

    cout << "Please enter your account : ";
    getline(cin, acc);
    cout << "\nPlease enter PIN : ";
    getline(cin, pass);

    for (int i = 0; i < 3 ; i++)
    {
        if (accounts[i].login(acc, pass))
        {
            status = true;
            cout << "\nWelcome " << accounts[i].getName() 
                << " .Please press any key to continue\n";
            return (i);
        }
    }
    cout << "\nSorry! Account or PIN is incorrect\n";
    return (0);
}

/*
option
=======
- get use to input option (option not avaible do something)
- use if statement straight call method
- if exit return true
*/
bool option(Account &acc)
{
    cout << "Select Options\n"
        << "1. Check balance\n"
        << "2. Cash Withdrawal\n"
        << "3. Show User Details\n"
        << "4. Update Mobile no.\n"
        << "5. Exit\n";
    char c = getChar();
    cout << "\n";

    cout << "Selected option: " << c << "\n";
    switch (c)
    {
        case '1': acc.checkBalance(); break;
        case '2': acc.withdraw(); break;
        case '3': acc.getInfo(); break;
        case '4': acc.updatePhone(); break;
        case '5': return true;
        default:
            cout << "Wrong input\n";
    }
    return false;
}