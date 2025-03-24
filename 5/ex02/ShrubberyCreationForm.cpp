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

#include "ShrubberyCreationForm.hpp"

//=============================================================================
// Custom Exception
//=============================================================================

const char *ShrubberyCreationForm::outFileErrorException::what() const throw()
{return "Fail to create or open file\n";}

//=============================================================================
// Constructor & Destructor
//=============================================================================

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), Target("<Unnamed>")
{std::cout << "ShrubberyCreationForm: Default CT\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const str &target)
: AForm("ShrubberyCreationForm", 145, 137), Target(target.empty()? "<Unnamed>" : target)
{std::cout << "ShrubberyCreationForm: Parametric CT\n";}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original)
: AForm("ShrubberyCreationForm", 145, 137), Target(original.getTarget())
{std::cout << "ShrubberyCreationForm: Copy CT\n";}

ShrubberyCreationForm::~ShrubberyCreationForm()
{std::cout << "ShrubberyCreationForm: Destroy " << Target << "\n";}

//=============================================================================
// Overload operator
//=============================================================================

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
    if (this != &original)
        this->Target = original.getTarget();
    return *this;
}

//=============================================================================
// Setter & Getter
//=============================================================================

const str ShrubberyCreationForm::getTarget() const 
{return Target;}

//=============================================================================
// Other Methods
//=============================================================================

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{   
    if (!this->getIsSign())
        throw NotApproveException();
    if (!executor.executeForm(*this))
        throw GradeTooLowException("Can't execute: ");

    std::ofstream outFile((Target + "__shrubbery").c_str());
    if (!outFile.is_open()) throw outFileErrorException();
    
    outFile << "\n"
    << "               ,@@@@@@@,                \n"
    << "       ,,,.   ,@@@@@@/@@,  .oo8888o.    \n"
    << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o   \n"
    << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'  \n"
    << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'  \n"
    << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'   \n"
    << "   `&%\\ ` /%&'    |.|        \\ '|8'     \n"
    << "       |o|        | |         | |       \n"
    << "       |.|        | |         | |       \n"
    << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/\n";        
    outFile.close();
    std::cout << GREEN << Target << "__shrubbery successfully planted\n" RESET; 
}
