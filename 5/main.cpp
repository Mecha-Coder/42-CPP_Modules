#include <iostream>
#include <string>



typedef std::string str;


class custom_exception: public std::exception
{
    virtual const char* what() const noexcept
    {
       return "Custom Exception"; 
    }
};


class Done: public std::exception
{
    public:
        virtual const char* what() const noexcept
        {
            
        }
};

class Bureaucrat
{
    str _name;
    int _grade;

    public:

        Bureaucrat(str name, int grade);


        
        class GradeTooLowException;
        class InvalidNameException;


        str getName(void) const;
        int getGrade(void) const;
        
        void incrementGrade(void);
        void decrementGrade(void);


};



Bureaucrat::Bureaucrat(str name, int grade)
{
    _name = name;
    _grade = grade;
}



//==================================================
// Exception
//==================================================


//==================================================
// Constructor & Destructor
//==================================================



//==================================================
// Setter and getter
//==================================================

string Bureaucrat::getName(void) const
{return (_name);}

int Bureaucrat::getGrade(void) const
{return (_grade);}

//==================================================
// Exception
//==================================================

string Bureaucrat::gradeTooHighException(void)
{return "Grade too high";}

string Bureaucrat::gradeTooLowException(void)
{return "Grade too low";}

string Bureaucrat::invalidNameException(void)
{return "Invalid name";}

//==================================================
// Other Methods
//==================================================

// Increment 3 -> 2
void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw gradeTooHighException();
}

// Decrement 6 -> 7
void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw gradeTooLowException();
}


int main()
{
    try
    {
        Bureaucrat candidate_A("Timmy", 2);
        Bureaucrat candidate_B("Maggie", 160);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
