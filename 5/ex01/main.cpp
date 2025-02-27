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
    str name[] = {"Form_A", "Form_B","", "Form_C"};
    int grade[] = {0, 160, 2, 15};
    int execute[] = {5,10, 20, 200};

    for (int i=0; i < 4; i++)
    {
        try 
            {Form form(name[i], grade[i], execute[i]);}
        catch(const std::exception& e)
            {std::cerr << RED "Construction exception: " RESET << e.what() << '\n';}
        std::cout << "----------------------------------------------------\n";
    }
    std::cout << "\n\n";
}

int main()
{
    // - Blank  name
    // - Grade set too high
    // - Grade set too low
    std::cout << "\nInvalid creation\n=====================================\n";
    invalid_creation();
    
    std::cout << "\nCreate test object\n================================================\n";
    Bureaucrat timmy("Timmy", 2);
    Bureaucrat elsa("Elsa", 147);
    Form form1("Form_2B", 10, 10);
    std::cout << form1 << "\n";
    Form form2("Form_EE", 150, 150);
    std::cout << form2 << "\n";


    std::cout << "\n\n\nForm Signing Test"
    << "\n====================================================\n";

    std::cout << "\n*********************************\nGrade is insufficient to sign the form"
        << "\n*********************************\n";
   
    try {form1.beSigned(elsa);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n*********************************\nSigning unsigned form" 
        << "\n*********************************\n";

    try {form1.beSigned(timmy);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    try {form2.beSigned(elsa);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n*********************************\nTForm already signed "
        << "\n*********************************\n";
    try {form2.beSigned(timmy);}
    catch (const std::exception& e){std::cerr << RED "Signing exception: " RESET << e.what() << '\n';}

    std::cout << "\n\n=============================================================\n\n";
}