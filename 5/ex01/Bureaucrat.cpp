/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:55:09 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 12:55:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{return ("Grade can't be greater than 1");}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{return ("Grade can't be lower than 150");}

const char *Bureaucrat::InvalidNameException::what() const throw()
{return ("Bureaucrat name can't be blank");}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Bureaucrat::Bureaucrat(str name, int grade)
{
    std::cout << "Bureaucrat: Parametric constructor called\n";
    if (grade < maxGrade)
        throw Bureaucrat::GradeTooHighException();
    if (grade > minGrade)
        throw Bureaucrat::GradeTooLowException();
    if (name.empty())
        throw Bureaucrat::InvalidNameException();
    _name = name;
    _grade = grade;
    std::cout << "Bureaucrat: Name= " << name << " Grade= "<< grade << "\n";
}

Bureaucrat::~Bureaucrat()
{std::cout << "Bureaucrat: " << _name << " destroyed\n";}

Bureaucrat::Bureaucrat() 
{std::cout << "Bureaucrat: Default constructor called. Nothing is set\n";} 

Bureaucrat::Bureaucrat(Bureaucrat const &other) 
{
	std::cout << "Bureaucrat: Copy constructor called\n";
    _name = other.getName(); 
    _grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat: Assignment constructor called" << "\n";
    if (this != &other)
    {
        _name = other.getName();
        _grade = other.getGrade();
    }
    return (*this);
}

//=============================================================================
// Setter & Getter
//=============================================================================

str Bureaucrat::getName() const
{return (_name);}

int Bureaucrat::getGrade(void) const
{return (_grade);}

//=============================================================================
// Other Methods
//=============================================================================

// Increment 3 -> 2
void Bureaucrat::incrementGrade()
{
    if (_grade == maxGrade)
        throw GradeTooHighException();
    _grade--;
}

// Decrement 6 -> 7
void Bureaucrat::decrementGrade(void)
{
    if (_grade == minGrade)
        throw GradeTooLowException();
    _grade++;
}

//=============================================================================
// Overload << Insertion Operator
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade(); 
    return (out);
}