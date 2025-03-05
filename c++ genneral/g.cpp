#include <iostream>
using namespace std;

/*
Abstraction
============
- show the important info while hiding the unimportant and complex details
Coffee machine example

- abstract: hide complex detail behind simple procedure
- abstract: (user end) don't change often

- abstraction layer that hides the complex logic from the end user
- we use abstract class -> which contain 1 pure virtual functio

Important:
==========
- We can't create instances of abstract classes
- But, we can create pointer of abstract classes
- Abstract don't have implementation

*/

class Smartphone{
public:
    virtual void TakeSelfie() = 0;
    virtual void MakeACall() = 0;
};

class Andriod : public Smartphone{  // <--- signing smartphone contract
public:
    void TakeSelfie(){
        cout << "Andriod: Take a selfie\n";
    }

    void MakeACall(){
        cout << "Andriod: calling\n";
    }
};

class Iphone : public Smartphone{  // <--- signing smartphone contract
public:
    void TakeSelfie(){
        cout << "Iphone: Take a selfie\n";
    }

    void MakeACall(){
        cout << "Iphone: calling\n";
    }
};

int main()
{
    Smartphone *s1 = new Andriod();
    Smartphone *s2 = new Iphone();
    s1->TakeSelfie();
    s1->MakeACall();
    s2->TakeSelfie();
    s2->MakeACall();
}