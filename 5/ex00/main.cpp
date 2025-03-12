/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:12:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 18:11:11 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define up 1
#define down 0

void invalid_creation()
{
    str name[] = {"Syahrul","Don",""};
    int grade[] = {0, 160, 2};

    for (int i=0; i < 3; i++)
    {
        try { Bureaucrat person(name[i], grade[i]); }
        catch (const std::exception& e)
            { std::cerr << RED "Construction failed: " RESET << e.what() << '\n';}
        std::cout << "-------------------------------------------------------\n";
    }
    std::cout << "\n\n";
} 

void out_of_range(str name, int grade, int action)
{
    try
    {
        Bureaucrat person(name, grade);
        while (1)
        {
            if (action)
                person.upGrade();
            else
                person.downGrade();
            std::cout << person << "\n";
        }
    }
    catch (const std::exception& e)
        {std::cerr << RED "Out of range: " RESET << e.what() << '\n';}
        std::cout << "-------------------------------------------------------\n";
}


int main()
{
    std::cout << YELLOW
              << "\n1) Instantiate bureaucrat with invalid info"
              << "\n============================================\n"
              << RESET;
    invalid_creation();

    std::cout << YELLOW
              << "\n2) Upgrade or Downgrade not within range"
              << "\n========================================\n"
              << RESET;
    out_of_range("Timmy", 2, up);
    out_of_range("Elsa", 147, down);

    std::cout << YELLOW
              << "\n\n3) Normal case without exception"
              << "\n==================================\n"
              << RESET;
    try
    {
        Bureaucrat test("Maggie", 5);
        std::cout << "-------------------------------------------------------\n";
        test.downGrade();
        std::cout << test << "\n";
        test.downGrade();
        std::cout << test << "\n";
        test.downGrade();
        std::cout << test << "\n";
        test.upGrade();
        std::cout << test << "\n";
        std::cout << "----------------------------------------------------\n";
        Bureaucrat imposter_1(test);
        std::cout << imposter_1 << "\n";
        std::cout << "----------------------------------------------------\n";
        Bureaucrat imposter_2;
        imposter_2 = test;
        std::cout << imposter_2 << "\n";
        std::cout << "----------------------------------------------------\n";
    }
    catch(const std::exception& e)
        {std::cerr << RED "Not to catch exception: " RESET << e.what() << '\n';}
    std::cout << "\n";
}