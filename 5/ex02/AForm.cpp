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

#include "AForm.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

AForm::GradeTooHighException::GradeTooHighException(str s) : msg(s + " grade too high") {}
AForm::GradeTooLowException::GradeTooLowException(str s) : msg(s + " grade too low") {}

const char *AForm::GradeTooHighException::what() const throw()
{return (msg.c_str());}

const char *AForm::GradeTooLowException::what() const throw()
{return (msg.c_str());}

const char *AForm::InvalidNameException::what() const throw()
{return ("Form name can't be empty");}

//=============================================================================
// Constructor & Destructor
//=============================================================================

AForm::AForm(str setName, int setApprover, int setActioner)
: name(setName), isSigned(false), signGrade(setApprover), executeGrade(setActioner)
{
    std::cout << "Form: Parametric constructor called\n";
    if (signGrade < maxGrade)       throw AForm::GradeTooHighException("Sign");
    if (executeGrade < maxGrade)    throw AForm::GradeTooHighException("Execute");

    if (signGrade > minGrade)       throw AForm::GradeTooLowException("Sign");
    if (executeGrade > minGrade)    throw AForm::GradeTooLowException("Execute");

    if (name.empty())               throw AForm::InvalidNameException();
    std::cout << *this << "\n";
}

AForm::~AForm()
{std::cout << "Form: " << name << " destroyed\n";}

AForm::AForm() 
: name("<blank>"), isSigned(false), signGrade(150), executeGrade(150)
{std::cout << "Form: Default constructor called. Set to default value\n";} 

AForm::AForm(AForm const &other) 
: name(other.getName()) , isSigned(other.getIsSigned()), signGrade(other.getSignGrade()), executeGrade(other.getExecuteGrade())
{std::cout << "Form: Copy constructor called\n";}

AForm& AForm::operator=(const AForm &other)
{
    std::cout << "Form: Assignment constructor called" << "\n";
    if (this != &other)
        isSigned = other.getIsSigned(); // Can't COPY constant
    return (*this);
}

//=============================================================================
// Setter & Getter
//=============================================================================

str AForm::getName() const
{return (name);}

int AForm::getSignGrade() const
{return (signGrade);}

int AForm::getExecuteGrade() const
{return (executeGrade);}

bool AForm::getIsSigned() const
{return (isSigned);}

//=============================================================================
// Other Methods
//=============================================================================

void AForm::beSigned(Bureaucrat &approver)
{
    if (isSigned)
        std::cout << "Form: " << name << " already signed\n";
    else if(approver.getGrade() <= signGrade)
    {
        isSigned = true;
        approver.signForm(name, "");
    }
    else
    {
        approver.signForm(name, "grade too low");
        throw AForm::GradeTooLowException("Approval"); 
    }
}

//=============================================================================
// Overload << Insertion Operator
//=============================================================================

std::ostream& operator<<(std::ostream& out, const AForm &obj)
{
    out << "\nForm Detail:\n"
        << "============\n"
        << "Form Name    : " << obj.getName() << "\n"
        << "Signed       : " << (obj.getIsSigned() ? "True" : "False") << "\n"
        << "Approval Grd : " << obj.getSignGrade() << "\n"
        << "Actioner Grd : " << obj.getExecuteGrade() << "\n";

    return (out);
}
