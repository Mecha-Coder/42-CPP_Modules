/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:44:55 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 20:44:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//=============================================================================
// Constructor & Destructor
//=============================================================================

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), Target("<Unnamed>")
{std::cout << "PresidentialPardonForm: Default CT\n";}

PresidentialPardonForm::PresidentialPardonForm(const str &target)
: AForm("PresidentialPardonForm", 25, 5), Target(target.empty()? "<Unnamed>" : target)
{std::cout << "PresidentialPardonForm: Parametric CT\n";}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
: AForm("PresidentialPardonForm", 25, 5), Target(original.getTarget())
{std::cout << "PresidentialPardonForm: Copy CT\n";}

PresidentialPardonForm::~PresidentialPardonForm()
{std::cout << "PresidentialPardonForm: Destroy " << Target << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
    if (this != &original)
        this->Target = original.getTarget();
    return *this;
}

//=============================================================================
// Setter & Getter
//=============================================================================

const str PresidentialPardonForm::getTarget() const 
{return Target;}

//=============================================================================
// Other Methods
//=============================================================================

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{   
    if (!this->getIsSign())
        throw NotApproveException();
    if (!executor.executeForm(*this))
        throw GradeTooLowException("Can't execute: ");
    std::cout << Target << " has been pardoned by Zaphod Beeblebrox\n";
}
