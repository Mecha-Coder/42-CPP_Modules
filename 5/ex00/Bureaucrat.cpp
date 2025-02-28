/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:55:09 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 18:15:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *Bureaucrat::GradeTooHighException::what() const throw()
{return ("Grade too high");}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{return ("Grade too low");}

const char *Bureaucrat::InvalidNameException::what() const throw()
{return ("Bureaucrat's name can't be empty");}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Bureaucrat::Bureaucrat(str setName, int setGrade) : name(setName), grade(setGrade)
{
    std::cout << "Bureaucrat: Parametric constructor called\n";
    if (grade < maxGrade)
        throw Bureaucrat::GradeTooHighException();
    if (grade > minGrade)
        throw Bureaucrat::GradeTooLowException();
    if (name.empty())
        throw Bureaucrat::InvalidNameException();
    std::cout << *this << "\n";
}

Bureaucrat::~Bureaucrat()
{std::cout << "Bureaucrat: " << name << " destroyed\n";}

Bureaucrat::Bureaucrat() : name("<blank>") , grade(150)
{std::cout << "Bureaucrat: Default constructor called\n";} 

Bureaucrat::Bureaucrat(Bureaucrat const &other)
: name(other.getName()) ,grade(other.getGrade())
{std::cout << "Bureaucrat: Copy constructor called\n";}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat: Assignment constructor called" << "\n";
    if (this != &other)
        grade = other.getGrade(); // Can't assign name because it is a constant
    return (*this);
}

//=============================================================================
// Setter & Getter
//=============================================================================

str Bureaucrat::getName() const
{return (name);}

int Bureaucrat::getGrade() const
{return (grade);}

//=============================================================================
// Other Methods
//=============================================================================

// Increment 3 -> 2
void Bureaucrat::upGrade()
{
    if (grade == maxGrade)
        throw GradeTooHighException();
    grade--;
}

// Decrement 6 -> 7
void Bureaucrat::downGrade()
{
    if (grade == minGrade)
        throw GradeTooLowException();
    grade++;
}

//=============================================================================
// Overload << Insertion Operator
//=============================================================================

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade(); 
    return (out);
}