#include <iostream>
#include <string>
using namespace std;

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class Bureaucrat
{
    const string Name;
    int Grade;
public:

    class GradeTooHighException : public exception
    {public: 
        const char *what() const throw()
        {return "grade too high\n";}
    };

    class GradeTooLowException : public exception
    {public: 
        const char *what() const throw()
        {return "grade too low\n";}
    };

    Bureaucrat() : Name("Unknown"), Grade(150)
    {cout << "Bureaucrat: Default CT\n";}

    Bureaucrat(const char *name, int grade)
    : Name((name && *name)? name : "Unknown") 
    {   
        if (grade < 1)   throw GradeTooHighException(); 
        if (grade > 150) throw GradeTooLowException();
        Grade = grade;    
        cout << "Bureaucrat: Parametric CT\n";
    }

    Bureaucrat(const Bureaucrat &original)
    : Name(original.Name), Grade(original.Grade) 
    {cout << "Bureaucrat: Copy CT\n";}

    Bureaucrat& operator=(const Bureaucrat &original)
    {
        if (this != &original)
        {
            //this->Name = original.getName(); <---can't work because Name is const 
            this->Grade = original.getGrade();
        }
        {cout << "Bureaucrat: Assignment operator\n";}
        return *this;
    }

    const string &getName() const  {return Name;}
    int getGrade() const           {return Grade;}

    void increment()
    {(Grade <= 1) ? throw GradeTooHighException() : Grade--;}
        
    void decrement()
    {(Grade >= 150) ? throw GradeTooLowException() : Grade++;}

    ~Bureaucrat() {cout << "Bureaucrat: Destroy " << Name << endl;}
};

ostream& operator<<(ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n"; 
    return out;
}

int main()
{
    // Output: "Unknown" & 150
    cout << "1) Test default constructor\n"
         << "===========================\n";
    Bureaucrat df;
    cout << df << "\n";

    /*
    2) Test with parametric constructor
        Invalid input
        - grade is too low
        - grade is too high
        - no name
        - null name
        Then ok input
    */
    cout << "2) Test with parametric constructor\n"
         << "====================================\n";
    cout << RED "Invalid input" RESET "\n";

    const char *names[] = {"Monkey", "Donkey", "" , NULL};
    int grades[] = {170, 0, 50, 50};
    

    for (int i=0; i < 4; i++)
    {
        try  
        {
            Bureaucrat test(names[i], grades[i]);
            cout << test << "\n---------------------------------\n";
        }
        catch (const exception &e)
        {cout << "Construction fail: " << e.what() << endl;}
    }

    cout << GREEN "OK" RESET "\n";
    try {
        Bureaucrat p1("Donald", 1);
        cout << p1 << endl;
        
    }
    catch (const exception &e)
    {cout << "Construction fail: " << e.what() << endl;}

    /* 3) Copy constructor */
    Bureaucrat trump("Trump", 1);
    Bureaucrat copy(df);

    
    /* 4) Reassignment operator */
    copy = trump;

    /* 5) Increment & decrement 
        - out of range
        Then ok input
    */
   try {}
   trump.increment();
   df.decrement();


}
