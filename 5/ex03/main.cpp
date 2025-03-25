/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:41:57 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/23 22:41:57 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// {"shrubbery creation", "robotomy request", "presidential pardon"}
int main()
{
    Intern newby;
    AForm *form1, *form2, *form3;
    std::cout << "\n--------------------------------------------------\n";
    
    try
    {
        form1 = newby.makeForm("shrubbery creation", "Backyard");
        std::cout << "\n--------------------------------------------------\n";
        form2 = newby.makeForm("robotomy request", "Refurbish toilet");
        std::cout << "\n--------------------------------------------------\n";
        form3 = newby.makeForm("presidential pardon", "Jason");
        std::cout << "\n--------------------------------------------------\n";
        
        std::cout << GREEN "View all created forms\n\n" RESET;
        std::cout << "Target = " << form1->getTarget() << *form1; 
        std::cout << "Target = " << form2->getTarget() << *form2;
        std::cout << "Target = " << form3->getTarget() << *form3; 
        
        delete form1;
        delete form2;
        delete form3;

        std::cout << "\n--------------------------------------------------\n";
        
        form1 = newby.makeForm("dasdsad", "hjkdhsajkdsa");
        delete form1;
    } 
    catch (const exception &e)
    {std::cout << RED "Exception caught: " RESET << e.what();}
}