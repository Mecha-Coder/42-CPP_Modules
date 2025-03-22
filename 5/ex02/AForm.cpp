/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:09:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 18:15:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

AForm::GradeTooHighException::GradeTooHighException(const string &msg)
: Msg(msg + "grade too high\n"){}

AForm::GradeTooLowException::GradeTooLowException(const string &msg) 
: Msg(msg + "grade too low\n"){}

const char *AForm::GradeTooHighException::what() const throw()
{return Msg.c_str();}

const char *AForm::GradeTooLowException::what() const throw()
{return Msg.c_str();}

//=============================================================================
// Constructor & Destructor
//=============================================================================

AForm::AForm()
: Name("<Unknown>"), SignGrade(150), ExecuteGrade(150), IsSign(false)   // Default
{cout << "Form: Default CT called\n";}


AForm::AForm(const string &name, int signGrade, int execGrade)   // Parametric
: Name((name.empty())? "<Unknown>" : name),  SignGrade(signGrade), ExecuteGrade(execGrade), IsSign(false)
{   
    if (SignGrade < 1)   throw GradeTooHighException("Sign_Grade: "); 
    if (SignGrade > 150) throw GradeTooLowException("Sign_Grade: ");
    
    if (ExecuteGrade < 1)    throw GradeTooHighException("Execute_Grade: "); 
    if (ExecuteGrade > 150)  throw GradeTooLowException("Execute_Grade: ");
    
    cout << "Form: Parametric CT called\n";
}

AForm::AForm(const AForm &original)   // Copy
: Name(original.getName()), SignGrade(original.getSignGrade()), ExecuteGrade(original.getExecuteGrade()), IsSign(original.getIsSign())
{cout << "Form: Copy CT\n";}

AForm::~AForm() 
{cout << "Form: Destroy " << Name << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

AForm &AForm::operator=(const AForm &original)
{
    {cout << "Form: Copy AS OPT\n";}
    if (this != &original)
    {
        // All these values are constant
        // this->Name = original.getName();
        // this->SignGrade = original.getSignGrade();
        // this->ExecuteGrade = original.getExecuteGrade();

        this->IsSign = original.getIsSign();
    }
    return *this;
}

//=============================================================================
// Setter & Getter
//=============================================================================

const string &AForm::getName() const {return Name;}

int AForm::getSignGrade() const {return SignGrade;}

int AForm::getExecuteGrade() const {return ExecuteGrade;}

bool AForm::getIsSign() const {return IsSign;}

//=============================================================================
// Other Methods
//=============================================================================

void AForm::beSigned(Bureaucrat &obj)
{   
    if (IsSign)
        cout << "Form " << Name << " already signed\n";
    else if (obj.getGrade() <= SignGrade)
    {
        IsSign = true;
        obj.signForm(IsSign, Name);
    }
    else
    {
        obj.signForm(IsSign, Name, "grade too low");
        throw GradeTooLowException("Can't sign: ");    
    }
}

//=============================================================================
// Ostream Insertion Operator
//=============================================================================

ostream &operator<<(ostream &out, const AForm &obj)
{
    out << "\n"
        << "Form name     : " << obj.getName() << "\n"
        << "Sign grade    : " << obj.getSignGrade() << "\n"
        << "Execute grade : " << obj.getExecuteGrade() << "\n"   
        << "Already signed: " << (obj.getIsSign()? "Yes" : "No") << "\n"
        << "\n";
    return out;
}
