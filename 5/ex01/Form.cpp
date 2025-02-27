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

const char *Form::GradeTooHighException::what() const throw()
{return ("Grade can't be greater than 1");}

const char *Form::GradeTooLowException::what() const throw()
{return ("Grade can't be lower than 150");}

const char *Form::InvalidNameException::what() const throw()
{return ("Form name can't be blank");}

const char *Form::CannotSignException::what() const throw()
{return ("Can't sign form");}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Form::Form(str name, int signGrade, int executeGrade) : 
_name(name), _signStatus(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "Form: Parametric constructor called\n";
    if (_signGrade < maxGrade || _executeGrade < maxGrade)
        throw Form::GradeTooHighException();
    if (_signGrade > minGrade || _executeGrade > minGrade)
        throw Form::GradeTooLowException();
    if (name.empty())
        throw Form::InvalidNameException();
}

Form::~Form()
{std::cout << "Form: " << _name << " destroyed\n";}

Form::Form() 
: _name("<blank>"), _signStatus(false), _signGrade(150), _executeGrade(150)
{std::cout << "Form: Default constructor called. Set to default value\n";} 

Form::Form(Form const &other) 
: _name(other.getName()) , _signStatus(other.getSignStatus()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{std::cout << "Form: Copy constructor called\n";}

Form& Form::operator=(const Form &other)
{
    std::cout << "Form: Assignment constructor called" << "\n";
    if (this != &other)
        _signStatus = other.getSignStatus(); // Can't COPY constant
    return (*this);
}

//=============================================================================
// Setter & Getter
//=============================================================================

str Form::getName() const
{return (_name);}

int Form::getSignGrade() const
{return (_signGrade);}

int Form::getExecuteGrade() const
{return (_executeGrade);}

bool Form::getSignStatus() const
{return (_signStatus);}

//=============================================================================
// Other Methods
//=============================================================================

void Form::beSigned(Bureaucrat &obj)
{
    if (_signStatus)
        std::cout << "Form: " << _name << " already signed ";
    
    else if(obj.getGrade() <= _signGrade)
    {
        _signStatus = true;
        obj.signForm(_name, _signStatus);
    }

    else
    {
        obj.signForm(_name, _signStatus);
        throw Form::CannotSignException(); // Replace Form::GradeTooLowException();
    }
}

//=============================================================================
// Overload << Insertion Operator
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Form &obj)
{
    out << "\nForm Detail:\n"
        << "--------------------------------------------------\n"
        << "Form Name      : " << obj.getName() << "\n"
        << "Signed Status  : " << (obj.getSignStatus() ? "True" : "False") << "\n"
        << "Grade approval : " << obj.getSignGrade() << " and higher\n"
        << "Group incharge : " << obj.getExecuteGrade() << " and below\n"
        << "--------------------------------------------------\n";
    return (out);
}
