#include <iostream>
using namespace std;

/*
Destructor

~ Class_name

- don't receive parameters
- place in the public area of the class
- only can have 1 destructor (while constructor can have many)

- invoke when object is being destroyed
  * explicitly destroyed using delete keyword
  * or variable go out of scope
- constructor and destructor be in the public section of the class
- destructor will be invoked in the reverse order of the constructor

Normal delete && Array delete
=================================

Normal --> delete object
Array --> delete [] object

- when use heap allocation, destructor is a must


Copy constructor
===================
- create a new object based on an existing object
- copy anything inside obj1 to obj2 given both from the same class
- if we didn't define copy constructor c++ will create a default one 

Class obj2(obj1)  

*/

class Book
{
public:
    string Title;
    string Author;
    int *Rates;
    int RatesCounter;

    Book(string title, string author){
        Title = title;
        Author = author;

        RatesCounter = 2;
        Rates = new int[RatesCounter];
        Rates[0] = 4;
        Rates[1] = 5;
        cout << Title + " constructor invoked\n"; 
    }

    Book(const Book &original){     // <--- define like this
        Title = original.Title;
        Author = original.Author;
        RatesCounter = original.RatesCounter;
        Rates = new int[RatesCounter];
        // Rates[0] = original.Rates[0];
        // Rates[1] = original.Rates[1];
        for (int i = 0; i < RatesCounter; i++)
            Rates[i] = original.Rates[i];
    }

    ~Book(){
        delete [] Rates;
        Rates = nullptr;
        cout << Title + " destructor invoke\n";
    }
};


void PrintBook(Book book)
{
    cout << "Title: " << book.Title << "\n";
    cout << "Author: " << book.Author << "\n"; 

    float sum = 0;
    for (int i = 0; i < book.RatesCounter; i++)
        sum += book.Rates[i];
    cout << "Avg rate:" << sum/book.RatesCounter << "\n";
}


int main()
{
    Book book1("Millionaire Fastlane", "M. J. Demarco");
    Book book2("C++ Lambda Story", "Bartek Filipek");

    Book book3(book2);
    // Book book3=book1  <---- is also a copy constructor

    // When a new object is being created based on a existing object is considered a copy constructor

    // Assignment operator will be invoke when re-assign new value to existing object

    /*2 Usage of copy constructor when compiler create a temp object
        Passing a object as a parameter (by value not by reference) to a function
        see example below
    */
   PrintBook(book1);

}
