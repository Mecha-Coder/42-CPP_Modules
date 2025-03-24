/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:50:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 21:50:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//=============================================================================
// Constructor & Destructor
//=============================================================================

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), Target("<Unnamed>")
{std::cout << "RobotomyRequestForm: Default CT\n";}

RobotomyRequestForm::RobotomyRequestForm(const str &target)
: AForm("RobotomyRequestForm", 72, 45),  Target(target.empty()? "<Unnamed>" : target)
{std::cout << "RobotomyRequestForm: Parametric CT\n";}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original)
: AForm("RobotomyRequestForm", 72, 45),  Target(original.getTarget())
{std::cout << "RobotomyRequestForm: Copy CT\n";}

RobotomyRequestForm::~RobotomyRequestForm()
{std::cout << "RobotomyRequestForm: Destroy " << Target << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
    if (this != &original)
        this->Target = original.getTarget();
    return *this;
}

//=============================================================================
// Setter & Getter
//=============================================================================

const str RobotomyRequestForm::getTarget() const 
{return Target;}

//=============================================================================
// Other Methods
//=============================================================================

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->getIsSign())
        throw NotApproveException();
    if (!executor.executeForm(*this))
        throw GradeTooLowException("Can't execute: ");
     
    std::cout << "\n"
    "     _      _ _ _ _               _ _  \n"
    "  __| |_ __(_) | (_)_ __   __ _  | | | \n"
    " / _` | '__| | | | | '_ \\ / _` | | | | \n"
    "| (_| | |  | | | | | | | | (_| | |_|_| \n"
    " \\__,_|_|  |_|_|_|_|_| |_|\\__, | (_|_) \n"
    "                           |___/       \n"     
    << "\n";

    // 50% chance of true
    srand(time(0) ^ clock());
    if (rand() % 2 == 0) 
        std::cout << GREEN << Target << " has been robotomized\n" RESET;
    else
        std::cout << RED "Robotomy failed\n" RESET;
}
