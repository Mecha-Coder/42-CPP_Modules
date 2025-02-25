/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 12:12:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define increase 1
#define decrease 0

void invalid_creation()
{
    str name[] = {"Syahrul","Don",""};
    int grade[] = {0, 160, 2};

    for (int i=0; i < 3; i++)
    {
        try 
            {Bureaucrat candidate(name[i], grade[i]);}
        catch(const std::exception& e)
            {std::cerr << "Construction exception: " << e.what() << '\n';}
        std::cout << "----------------------------------------------------\n";
    }
    std::cout << "\n\n";
}

void out_of_range(Bureaucrat &obj, int action)
{
    std::cout << "\n";
    try
    {
        while (1)
        {
            if (action)
                obj.incrementGrade();
            else
                obj.decrementGrade();
            std::cout << obj << "\n";
        }
    }
    catch(const std::exception& e)
        {std::cerr << "Out of range exception: " << e.what() << '\n';}
    std::cout << "----------------------------------------------------\n";
}



int main()
{
    // - Blank bureaucrat name
    // - Grade set too high
    // - Grade set too low
    std::cout << "\nInvalid creation\n===================\n";
    invalid_creation();

    // Error when increment and decremment go out of range
    std::cout << "\nOut of range scenario\n========================\n";
    Bureaucrat a("Timmy", 2);
    out_of_range(a, increase);
    Bureaucrat b("Elsa", 147);
    out_of_range(b, decrease);
    std::cout << "\n\n";

    // Normal case without errors
    std::cout << "\nNormal scenario\n====================\n";
    try
    {
        Bureaucrat test("Maggie", 5);
        test.decrementGrade();
        test.decrementGrade();
        test.incrementGrade();
        std::cout << test << "\n";
    }
    catch(const std::exception& e)
        {std::cerr << "Suppose not to catch exception: " << e.what() << '\n';}
    std::cout << "\n\n";

}