#include "header.cpp"

int Account::Counter = 1;

Account::Account(const string &name, int age, string &pass, int deposit, string phone)
{
    if (name.length() > 20 || name.empty() || !isAlphabet(name))
        throw std::runtime_error("Error: Invalid name");
    
    if (age < 17 || age > 100)
        throw std::runtime_error("Error: Invalid age");
    
    if (pass.length() != 6 || !isDigit(pass))
        throw std::runtime_error("Error: Invalid password");
    
    if (deposit > 20)
        throw std::runtime_error("Error: Insufficient initial deposit");
    
    if (phone.length() != 10 || !isDigit(phone))
        throw std::runtime_error("Error: Invalid Phone number");

    Name = name;
    Age = age;
    Password = pass;
    Balance = deposit;
    Phone = phone;
    AccountNo = "AC" + padWithZero(Counter++);
    cout << "Welcome " << Name << "! Your Account: " << AccountNo << " was successfully created\n"; 
}

void Account::checkBalance(){
    cout << "AccountNo: " << AccountNo << " | Balance:" << Balance << "\n";
}

void Account::withdraw(int amount, string pass){
    if (amount > Balance)
        cout << "Error: Withdrawal amount exceed total balance\n";
    else {
        Balance -= amount;
        cout << "Successful: Your balance is now " << Balance << "\n"; 
    }
}

void Account::getInfo(){
    cout << "Account ID: " << AccountNo << "\n"
         << "Name      : " << Name      << "\n"
         << "Age       : " << Age       << "\n"
         << "Phone     : " << Phone     << "\n"
         << "Balance   : " << Balance   << "\n"
         << "Password  : " << Password  << "\n\n";
}

void Account::updatePhone(string phone)
{
    if (phone.length() != 10 || !isDigit(phone))
        cout << "Error: Invalid Phone number\n";
    else {
        Phone = phone;
        cout << "New phone number saved";
    }
}