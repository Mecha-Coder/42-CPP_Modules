/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:19:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/23 21:19:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *Intern::FormException::what() const throw()
{return "Sorry! No such form exist\n";}

//=============================================================================
// Constructor & Destructor
//=============================================================================

Intern::Intern() {std::cout << "Intern: Default CT called\n";}
Intern::~Intern() {std::cout << "Intern: Destroy\n";}

//=============================================================================
// Other Methods
//=============================================================================

AForm *Intern::makeForm(const str &form, const str &target)
{
    AForm *newForm;
    str forms[] 
    = {"shrubbery creation", "robotomy request", "presidential pardon"};

    // Array of pointers to member functions
    AForm* (Intern::*methods[])(const str &target) 
    = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePardonForm};

    for (int i=0; i < 3; i++)
    {
        if (forms[i] == form)
        {
            newForm = (this->*methods[i])(target);
            std::cout << "Intern created " << form << "\n";
            return newForm;
        }
    }
    throw FormException();
    return NULL;
}

AForm *Intern::makeShrubberyForm(const str &target)
{return new ShrubberyCreationForm(target);}

AForm *Intern::makeRobotomyForm(const str &target)
{return new RobotomyRequestForm(target);}

AForm *Intern::makePardonForm(const str &target)
{return new PresidentialPardonForm(target);}
