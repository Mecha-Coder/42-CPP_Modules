/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:29:17 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 17:12:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
- sign grade too high
- sign grade too low
- execute grade too high
- execute grade too low
- blank name
- valid input
*/
void test_parametric_ct()
{
    std::cout << YELLOW
         << "\nInstantiate w/ valid & invalid input"
         << "\n=====================================\n";
    
    const char *names[] = {"AForm", "BForm", "CForm", "DForm", "" ,"EForm"};
    int signGrades[] = {170, 0, 50, 50, 50, 1};
    int executeGrade[] = {50, 50, 170, 0, 50, 1};
    
    for (int i=0; i < 6; i++)
    {
        try 
        {
            Form f1(names[i], signGrades[i], executeGrade[i]);
            std::cout << GREEN "OK: " RESET << f1 << "\n";
        }
        catch (const exception &e)
        {std::cout << RED "Construction fail: " RESET << e.what();}
        std::cout << "\n--------------------------------------------------\n";
    }
}


/*
- grade not suitable
- already signed
- suitable grade
*/
void test_form_signing()
{
    std::cout << YELLOW
         << "\n\n\nTest form signing"
         << "\n=================\n"
         << RESET;

    std::cout << "Init test\n***********\n";
    
    Bureaucrat trump("Trump", 1);
    Form A1("A1", 1, 10);
    std::cout << A1;

    Bureaucrat donald("Donald", 30);
    Form B1("B1", 50, 50);
    std::cout << B1;

    std::cout << "========================\n\n";

    try {A1.beSigned(donald);}
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
    
    try {
    std::cout << "\n--------------------------------------------------\n";
    B1.beSigned(donald);
    std::cout << "\n--------------------------------------------------\n";
    B1.beSigned(trump);
    std::cout << "\n--------------------------------------------------\n";
    A1.beSigned(trump);
    std::cout << "\n--------------------------------------------------\n";
    } catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}

    std::cout << GREEN "Confirm both A1 and B1 signed" RESET << A1 << B1;

    std::cout << "\n--------------------------------------------------\n";
}


int main()
{
    test_parametric_ct();
    test_form_signing();
}
