#include "header.hpp"

void Account::setAccount(string acc, string name, string phone, string pass, int age, int deposit)
{
    Account = acc;
    Name = name;
    Phone = phone;
    Password = pass;
    Age = age;
    Balance = deposit;
}

const string &Account::getName() const
{return Name;}

bool Account::login(string acc, string pass)
{return (Account == acc && Password == pass);}

void Account::withdraw() 
{
    int amount;

    cout << "Please enter amount : ";
    cin >> amount;

    if (amount > Balance || amount == 0)
        cout << "Invalid amount entered\n";
    else {
        Balance -= amount;
        cout << "Please take your cash withdrawal: " << amount << "\n"; 
    }
}

void Account::updatePhone()
{
    string oldnum, newnum;

    cout << "Please enter old phone number : ";
    getline(cin, oldnum);
    cout << "\nPlease enter new phone number : ";
    getline(cin, newnum);

    if (Phone == oldnum && isDigit(newnum)) {
        Phone = newnum;
        cout << "Your new phone number was updated\n";
    }
    else {cout << "Encountered problem when updating phone detail\n";}
}

void Account::checkBalance()
{cout << "Your current balance is " << Balance << "\n";}

void Account::getInfo()
{
    cout << "Account : " << Account << "\n"
         << "Name    : " << Name << "\n"
         << "Phone   : " << Phone << "\n"
         << "Age     : " << Age << "\n";
}
