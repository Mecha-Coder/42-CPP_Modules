/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:49:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/24 12:31:39 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_ShrubberyForm()
{
    std::cout << YELLOW
    << "\n1) Test Shrubbery Creation"
    << "\n===========================\n"
    << RESET;

    std::cout << "Init test\n***********\n";
    Bureaucrat trump("Trump", 1);
    Bureaucrat sarah("Sarah", 130);
    Bureaucrat brian("Brian", 150);
    ShrubberyCreationForm F1("Home");
    ShrubberyCreationForm F2("School");
    std::cout << "====================================\n\n";

    try {F1.execute(trump);} // Can't execute because hasn't signed
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    
    std::cout << "\n--------------------------------------------------\n";
    F1.beSigned(sarah);
    F2.beSigned(sarah);
    std::cout << "\n--------------------------------------------------\n";
    
    try {F1.execute(brian);}  // Grade too low
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    std::cout << "\n--------------------------------------------------\n";
    
    try {F1.execute(trump);}  // File is read-only
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    std::cout << "\n--------------------------------------------------\n";

    F2.execute(trump);
    std::cout << "\n--------------------------------------------------\n";
}

void test_RobotomyForm()
{
    std::cout << YELLOW
    << "\n2) Test Robotomy Request"
    << "\n=========================\n"
    << RESET;

    std::cout << "Init test\n***********\n";
    
    Bureaucrat trump("Trump", 1);
    Bureaucrat sarah("Sarah", 70);
    Bureaucrat brian("Brian", 150);
    RobotomyRequestForm F1("Road Construction");
    RobotomyRequestForm F2("Building Renovation");
    RobotomyRequestForm F3("Construct Statue of Trump");
    std::cout << "\n====================================\n";

    try {F1.execute(trump);} // Can't execute because hasn't signed
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    
    std::cout << "\n--------------------------------------------------\n";
    F1.beSigned(sarah);
    F2.beSigned(sarah);
    F3.beSigned(sarah);
    std::cout << "\n--------------------------------------------------\n";
    
    try {F1.execute(brian);}  // Grade too low
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    std::cout << "\n--------------------------------------------------\n";
    
    try {
    F1.execute(trump);
    std::cout << "\n--------------------------------------------------\n";
    F2.execute(trump);
    std::cout << "\n--------------------------------------------------\n";
    F3.execute(trump);
    std::cout << "\n--------------------------------------------------\n";
    }  catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
}

void test_PardonForm()
{
    std::cout << YELLOW
    << "\n3) Test Presidential Pardon"
    << "\n================================\n"
    << RESET;

    std::cout << "Init test\n***********\n";
    
    Bureaucrat trump("Trump", 1);
    Bureaucrat sarah("Sarah", 25);
    Bureaucrat brain("Brain", 110);
    PresidentialPardonForm F1("Kim Jong Un");
    std::cout << "\n====================================\n";

    try {F1.execute(trump);} // Can't execute because hasn't signed
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    
    std::cout << "\n--------------------------------------------------\n";
    F1.beSigned(sarah);
    std::cout << "\n--------------------------------------------------\n";
    
    try {F1.execute(brain);}  // Grade too low
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    std::cout << "\n--------------------------------------------------\n";
    
    F1.execute(trump);
    
    std::cout << "\n--------------------------------------------------\n";
}

int main()
{
    // AForm test; <---converted to abstract class
   test_ShrubberyForm(); // <--- chmod 444
//    test_RobotomyForm();
//    test_PardonForm();
}
