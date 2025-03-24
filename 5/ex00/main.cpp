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

/*
- grade is too low
- grade is too high
- no name
- NULL pointer
- valid input
*/
void test_parametric_ct()
{
    std::cout << YELLOW
         << "\nInstantiate w/ valid & invalid input"
         << "\n=====================================\n";
    
    const char *names[] = {"Monkey", "Donkey", "", NULL, "Donald"};
    int grades[] = {170, 0, 50, 10, 70};
    
    for (int i=0; i < 5; i++)
    {
        try 
        {
            Bureaucrat p1(names[i], grades[i]);
            std::cout << GREEN "OK: " RESET << p1 << "\n";
        }
        catch (const exception &e)
        {std::cout << RED "Construction fail: " RESET << e.what();}
        std::cout << "\n--------------------------------------------------\n";
    }
    std::cout << "\n\n";
}

void test_increase_decrease()
{
    std::cout << YELLOW
         << "\nGrade increment & decrement"
         << "\n===========================\n"
         << RESET;

    std::string names[] = {"Mickey", "Goofy", "Donald"};
    int grades[]   = {2, 148, 50};
    bool action[]  = {true, false, false};

    for (int i=0; i < 3; i++)
    {
        try 
        {
            Bureaucrat p1(names[i], grades[i]);
            if (action[i])
                std::cout << GREEN "start increment -> " RESET << p1;
            else
                std::cout << GREEN "start decrement -> " RESET << p1;
    
            for (int j=0; j < 4; j++)
            {
                action[i]? p1.increment() : p1.decrement();
                std::cout << p1;
            }
        }
        catch (const exception &e)
        {std::cout << RED "Exception caught: " RESET << e.what();}
        std::cout << "\n--------------------------------------------------\n";
    }
}

int main()
{
    test_parametric_ct();
    test_increase_decrease();
}
