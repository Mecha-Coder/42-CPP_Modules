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

void test_default_ct()
{
    cout << YELLOW
         << "\n1) Test default constructor"
         << "\n===========================\n"
         << RESET;
    Form df;
    cout << df << "\n";
}


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
    cout << YELLOW
         << "\n2) Test with parametric constructor"
         << "\n====================================\n";
    
    string names[] = {"AForm", "BForm", "CForm", "DForm", "" ,"EForm"};
    int signGrades[] = {170, 0, 50, 50, 50, 1};
    int executeGrade[] = {50, 50, 170, 0, 50, 1};
    
    for (int i=0; i < 6; i++)
    {
        try 
        {
            Form test(names[i], signGrades[i], executeGrade[i]);
            cout << GREEN "OK: " RESET << test << "\n";
        }
        catch (const exception &e)
        {cout << RED "Construction fail: " RESET << e.what();}
        cout << "\n--------------------------------------------------\n";
    }
}


void test_copy_and_assignment()
{
    cout << YELLOW
         << "\n3) Test copy CT and copy AS "
         << "\n===========================\n"
         << RESET;

    Bureaucrat p1("Trump", 1);
    Form a("B18", 1, 1);
    cout << "dummy = " << a << "\n";
    
    cout << "--------------------------------------------------\n";

    a.beSigned(p1);
    Form b(a);
    cout << "copy CT= " << b << "\n";

    cout << "--------------------------------------------------\n";
    
    Form c;
    cout << "original = " << c;
    c = a;
    cout << "re-assign = " << c << "\n";

    cout << "--------------------------------------------------\n";
}


/*
- grade not suitable
- already signed
- suitable grade
*/
void test_form_signing()
{
    cout << YELLOW
         << "\n4) Test form signing"
         << "\n===========================\n"
         << RESET;

    cout << "Init test\n***********\n";
    
    Bureaucrat Person1("Trump", 1);
    Form A1("A1", 1, 10);
    
    Bureaucrat Person2("Donald", 30);
    Form B1("B1", 50, 50);

    cout << "\n\n";

    try {A1.beSigned(Person2);}
    catch (const exception &e)
    {cout << RED "Exception caught: " RESET << e.what();}
    
    cout << "\n--------------------------------------------------\n";
    B1.beSigned(Person2);
    cout << "\n--------------------------------------------------\n";
    B1.beSigned(Person1);
    cout << "\n--------------------------------------------------\n";
    A1.beSigned(Person1);
    cout << "\n--------------------------------------------------\n";
}


int main()
{
    test_default_ct();
    test_parametric_ct();
    test_copy_and_assignment();
    test_form_signing();
}
