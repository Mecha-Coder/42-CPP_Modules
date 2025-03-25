/*
Exception 
- handle unwanted event during program execution
- throw exception - crash with error message
- unless we catch using try-catch block

catch (type)
catch (...) <--- default catch

e - is an object that has a method called what()

type of exception
- out_of_range
*/

#include <iostream>
using namespace std;

class custom_exception : public exception
{
    const char *what() const noexcept
    {return "Custom Exception";}
};

void function()
{throw 2.2;}


void example1()
{
    try
    {
        // string word = "four";
        // cout << word.at(4) << endl;
        // string withNULL = nullptr;
        // cout << withNULL << endl;
        function();
        throw 20;
        throw custom_exception(); // exception type error {like calling a function but it is a class}
    }
    catch (out_of_range &e) {cout << "Error : " << e.what() << endl;}
    catch (exception &e)    {cout << "Error : " << e.what() << endl;}
    catch (int code)        {cout << code << endl;}
    catch (...)             {cout << "Catch something" << endl;}         
}

void example2()
{
    try{
        throw 1;
        throw 1.1;
        throw 1.1f;
        throw 'a';
        throw "I am exception";
        throw string("std::string exception");
    }
    catch(const int &e)    {cout << "Int exception " << e << endl;}
    catch(const double &e) {cout << "Double exception " << e << endl;}
    catch(const float &e)  {cout << "Float exception " << e << endl;}
    catch(const char &e)   {cout << "char exception " << e << endl;}
    catch(const char* &e)  {cout << e << endl;}
    catch(const string &e) {cout << e << endl;}
}

class CustomExpection : public exception
{
    const char *errmsg;
    public:
    CustomExpection(const char *msg) : errmsg(msg) {}
    const char *what() const throw() 
    {return errmsg;}
};

void nested_function()
{
    throw CustomExpection("Try this exception!");
}

void example3()
{
    try {
     nested_function();   
    }
    catch (exception &e) {cout << e.what() << endl;}
}

int main()
{
   //example1();
   //example2();
   // User define-exception
    example3();
}