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

#include "Form.hpp"

void invalid_creation()
{
    str name[] = {"Form_A", "Form_B", "Form_C", "Form_D", ""};
    int grade[] = {0, 160, 2 ,5, 15};
    int execute[] = {5,10, 0, 200, 60};

    for (int i=0; i < 5; i++)
    {
        try {Form form(name[i], grade[i], execute[i]);}
        catch(const std::exception& e)
            {std::cerr << RED "Construction exception: " RESET << e.what() << '\n';}
        std::cout << "----------------------------------------------------\n";
    }
    std::cout << "\n\n";
}


// 1) 
int main()
{
    std::cout << YELLOW
        << "\n1) Instantiate form with invalid info"
        << "\n======================================\n"
        << RESET;
    invalid_creation();

    std::cout << "\n----------------------------------------------------\n";
    Bureaucrat timmy("Timmy", 2);
    Bureaucrat elsa("Elsa", 147);
    std::cout << "\n";
    Form form1("Form_2B", 10, 10);
    Form form2("Form_EE", 150, 150);
    std::cout << "\n------------------------------------------------------\n";

    std::cout << YELLOW
        << "\n\n2) Test Signing form with correct & incorrect grade"
        << "\n===================================================\n"
        << RESET;

    try {form1.beSigned(elsa);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n----------------------------------------------------\n";
    
    try {form1.beSigned(timmy);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n----------------------------------------------------\n";

    try {form2.beSigned(elsa);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << YELLOW
        << "\n\n\n3) Try to sign form that already signed"
        << "\n==========================================\n"
        << RESET;
    
    try 
    {
        std::cout << form2 << "\n";
        form2.beSigned(timmy);
    }
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n----------------------------------------------------\n";
}