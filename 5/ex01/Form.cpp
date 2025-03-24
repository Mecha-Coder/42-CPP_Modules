/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:09:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 17:14:19 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

Form::GradeTooHighException::GradeTooHighException(const str &msg)
: Msg(msg + "grade too high\n"){}

Form::GradeTooLowException::GradeTooLowException(const str &msg) 
: Msg(msg + "grade too low\n"){}

const char *Form::GradeTooHighException::what() const throw()
{return Msg.c_str();}

const char *Form::GradeTooLowException::what() const throw()
{return Msg.c_str();}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Form::Form()
: Name("<Unknown>"), SignGrade(150), ExecuteGrade(150), IsSign(false)
{std::cout << "Form: Default CT called\n";}


Form::Form(const str &name, int signGrade, int execGrade)
: Name((name.empty())? "<Unknown>" : name),  SignGrade(signGrade), ExecuteGrade(execGrade), IsSign(false)
{   
    if (SignGrade < 1)   throw GradeTooHighException("Sign_Grade: "); 
    if (SignGrade > 150) throw GradeTooLowException("Sign_Grade: ");
    
    if (ExecuteGrade < 1)    throw GradeTooHighException("Execute_Grade: "); 
    if (ExecuteGrade > 150)  throw GradeTooLowException("Execute_Grade: ");
    
    std::cout << "Form: Parametric CT called\n";
}

Form::Form(const Form &original)
: Name(original.getName()), SignGrade(original.getSignGrade()), ExecuteGrade(original.getExecuteGrade()), IsSign(original.getIsSign())
{std::cout << "Form: Copy CT\n";}

Form::~Form() 
{std::cout << "Form: Destroy " << Name << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

Form &Form::operator=(const Form &original)
{
    {std::cout << "Form: Copy AS OPT\n";}
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

const str &Form::getName() const {return Name;}

int Form::getSignGrade() const {return SignGrade;}

int Form::getExecuteGrade() const {return ExecuteGrade;}

bool Form::getIsSign() const {return IsSign;}

//=============================================================================
// Other Methods
//=============================================================================

void Form::beSigned(Bureaucrat &obj)
{   
    if (IsSign)
        std::cout << "Form " << Name << " already signed\n";
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

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "\n"
        << "Form name     : " << obj.getName() << "\n"
        << "Sign grade    : " << obj.getSignGrade() << "\n"
        << "Execute grade : " << obj.getExecuteGrade() << "\n"   
        << "Already signed: " << (obj.getIsSign()? "Yes" : "No") << "\n"
        << "\n";
    return out;
}
