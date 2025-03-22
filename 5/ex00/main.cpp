/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:45:58 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 12:07:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_default_ct()
{
    cout << YELLOW
         << "\n1) Test default constructor"
         << "\n===========================\n"
         << RESET;
    Bureaucrat df;
    cout << df << "\n";
}

/*
Checks performed
- grade is too low
- grade is too high
- no name
- valid input
*/
void test_parametric_ct()
{
    cout << YELLOW
         << "\n2) Test with parametric constructor"
         << "\n====================================\n";
    
    string names[] = {"Monkey", "Donkey", "", "Donald"};
    int grades[] = {170, 0, 50, 50};
    
    for (int i=0; i < 4; i++)
    {
        try 
        {
            Bureaucrat test(names[i], grades[i]);
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

    Bureaucrat a("Trump", 1);
    cout << "dummy = " << a << "\n";

    Bureaucrat b(a);
    cout << "copy CT= " << b << "\n";

    Bureaucrat c;
    cout << "original = " << c;
    c = a;
    cout << "re-assign = " << c << "\n";
}

void test_increase_decrease()
{
    cout << YELLOW
         << "\n4) Test grade increment / decrement"
         << "\n====================================\n"
         << RESET;

    string names[] = {"Monkey", "Donkey", "Donald"};
    int grades[]   = {2, 148, 50};
    bool action[]  = {true, false, false};

    for (int i=0; i < 3; i++)
    {
        try 
        {
            Bureaucrat test(names[i], grades[i]);
            if (action[i])
                cout << GREEN "start increment -> " RESET << test;
            else
                cout << GREEN "start decrement -> " RESET << test;
            for (int j=0; j < 4; j++)
            {
                action[i]? test.increment() : test.decrement();
                cout << test;
            }
        }
        catch (const exception &e)
        {cout << RED "Exception caught: " RESET << e.what();}
        cout << "\n--------------------------------------------------\n";
    }
}

int main()
{
    test_default_ct();
    test_parametric_ct();
    test_copy_and_assignment();
    test_increase_decrease();
}
