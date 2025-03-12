/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:28:20 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 19:49:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

Form::GradeTooHighException::GradeTooHighException(str s) : msg(s + " grade too high") {}
Form::GradeTooLowException::GradeTooLowException(str s) : msg(s + " grade too low") {}

const char *Form::GradeTooHighException::what() const throw()
{return (msg.c_str());}

const char *Form::GradeTooLowException::what() const throw()
{return (msg.c_str());}

const char *Form::InvalidNameException::what() const throw()
{return ("Form name can't be empty");}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Form::Form(str setName, int setApprover, int setActioner)
: name(setName), isSigned(false), signGrade(setApprover), executeGrade(setActioner)
{
    std::cout << "Form: Parametric constructor called\n";
    if (signGrade < maxGrade)       throw Form::GradeTooHighException("Sign");
    if (executeGrade < maxGrade)    throw Form::GradeTooHighException("Execute");

    if (signGrade > minGrade)       throw Form::GradeTooLowException("Sign");
    if (executeGrade > minGrade)    throw Form::GradeTooLowException("Execute");

    if (name.empty())               throw Form::InvalidNameException();
    std::cout << *this << "\n";
}

Form::~Form()
{std::cout << "Form: " << name << " destroyed\n";}

Form::Form() 
: name("<blank>"), isSigned(false), signGrade(150), executeGrade(150)
{std::cout << "Form: Default constructor called. Set to default value\n";} 

Form::Form(Form const &other) 
: name(other.getName()) , isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{std::cout << "Form: Copy constructor called\n";}

Form& Form::operator=(const Form &other)
{
    std::cout << "Form: Assignment constructor called" << "\n";
    if (this != &other)
        isSigned = other.getIsSigned(); // Can't COPY constant
    return (*this);
}

//=============================================================================
// Setter & Getter
//=============================================================================

str Form::getName() const
{return (name);}

int Form::getSignGrade() const
{return (signGrade);}

int Form::getExecuteGrade() const
{return (executeGrade);}

bool Form::getIsSigned() const
{return (isSigned);}

//=============================================================================
// Other Methods
//=============================================================================

void Form::beSigned(Bureaucrat &obj)
{
    if (isSigned)
        std::cout << "Form: " << name << " already signed\n";
    else if(obj.getGrade() <= signGrade)
    {
        isSigned = true;
        obj.signForm(name, "");
    }
    else
    {
        obj.signForm(name, "grade too low");
        throw Form::GradeTooLowException("Approval"); 
    }
}

//=============================================================================
// Overload << Insertion Operator
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Form &obj)
{
    out << "\nForm Detail:\n"
        << "============\n"
        << "Form Name    : " << obj.getName() << "\n"
        << "Signed       : " << (obj.getIsSigned() ? "True" : "False") << "\n"
        << "Approval Grd : " << obj.getSignGrade() << "\n"
        << "Actioner Grd : " << obj.getExecuteGrade() << "\n";

    return (out);
}
