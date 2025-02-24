#include <iostream>
#include <string>
using namespace std;

class custom_exception: public exception
{
    virtual const char* what() const noexcept
    {
       return "Custom Exception"; 
    }
};

class Printer
{
    string _name;
    int _totalPaper;
    
    public:
        Printer(string name, int paper);
        ~Printer();

        void print(const string& doc);
        void printRandom(void);
        void test_error(void);
};

Printer::Printer(string name, int paper): _name(name), _totalPaper(paper)
{
    cout << "Printer : Parametric constructor called\n" 
         << "* Name  : " << _name << "\n"
         << "* Paper : " << _totalPaper << "\n";
}

Printer::~Printer()
{cout << "\nDestroy " << _name << "\n";}

void Printer::printRandom(void)
{throw 4.234;}

void Printer::test_error(void)
{int *i = new int[99999999999999999];}

void Printer::print(const string& doc)
{
    int paperRequired = doc.length() / 5;
    
    if (!_totalPaper)
        throw 1;
    else if (paperRequired > _totalPaper)
        throw "Not enough paper to print this doc";

    _totalPaper-=paperRequired;
    cout << "\nPrinter: <" << _name << "> : " << doc <<  "\n"
            << "Balance paper = " << _totalPaper << "\n";
}


void try_catch_block(Printer &myPrinter, const string& s)
{
    try
        {myPrinter.print(s);}
    catch(const char *err_msg)
    {cout << "\nError: " << err_msg << "\n";}
        catch(int err_code)
    {cout << "\nError code : <" << err_code << "> Sorry, out of paper" << "\n";}
        catch(...)
    {cout << "\nError 3: " << "Default catch error" << "\n";}
}

int main()
{
    Printer myPrinter("HP Deskjet 1235", 25);

    try_catch_block(myPrinter, "Hello World");
    try_catch_block(myPrinter, "Nice to see you smilling");
    try_catch_block(myPrinter, "How is your day");
    try_catch_block(myPrinter, "Nice to see you smilling");
    try_catch_block(myPrinter, "Type something long to waste printing paper...hahaha");
    try_catch_block(myPrinter, "Type something long to waste printing paper...hahaha");
    try_catch_block(myPrinter, "Hello guys");
    try_catch_block(myPrinter, "Print more");

    try
        {myPrinter.printRandom();}
    catch(const char *err_msg)
        {cout << "\nError 1: " << err_msg << "\n";}
    catch(int err_code)
        {cout << "\nError 2: " << err_code << "\n";}
    catch(...)
        {cout << "\nError 3: " << "Default catch error" << "\n";}
    
    try
        {myPrinter.test_error();}
    catch(bad_alloc& err_msg)
        {cout << "\nError XX: " << err_msg.what() << "\n";}
    catch(...)
        {cout << "\nError 3: " << "Default catch error" << "\n";}

    try
    {
        cout << "\nTrying custom throw / exception\n=======================\n";
        throw custom_exception();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}


/* Note
- Catch hierarchy based on exception types
- Create own custom exception types
*/