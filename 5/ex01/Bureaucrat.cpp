/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:44:14 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 17:07:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{return "grade too high\n";}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{return "grade too low\n";}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Bureaucrat::Bureaucrat() : Name("<Unknown>"), Grade(150)  // Default
{cout << "Bureaucrat: Default CT called\n";}


Bureaucrat::Bureaucrat(const string &name, int grade)    // Parametric
: Name((name.empty())? "<Unknown>" : name)
{   
    if (grade < 1)   throw GradeTooHighException(); 
    if (grade > 150) throw GradeTooLowException();
    Grade = grade;    
    cout << "Bureaucrat: Parametric CT called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)       // Copy
: Name(original.getName()), Grade(original.getGrade()) 
{cout << "Bureaucrat: Copy CT\n";}

Bureaucrat::~Bureaucrat() 
{cout << "Bureaucrat: Destroy " << Name << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
    {cout << "Bureaucrat: Copy AS OPT\n";}
    if (this != &original)
    {
        //this->Name = original.getName(); <-- can't work because Name is const 
        this->Grade = original.getGrade();
    }
    return *this;
}

//=============================================================================
// Getter & Setter
//=============================================================================

const string &Bureaucrat::getName() const {return Name;}
int Bureaucrat::getGrade() const {return Grade;}

//=============================================================================
// Other Methods
//=============================================================================

void Bureaucrat::increment()
{(Grade <= 1) ? throw GradeTooHighException() : Grade--;}
    
void Bureaucrat::decrement()
{(Grade >= 150) ? throw GradeTooLowException() : Grade++;}

void Bureaucrat::signForm(bool status, const string &formName, string reason)
{
    if (status)
        cout << Name << " signed form " << formName << "\n";
    else
        cout << Name << " couldn't signed form " << formName << " because " << reason << "\n";
}

//=============================================================================
// Ostream Insertion Operator
//=============================================================================

ostream& operator<<(ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n"; 
    return out;
}