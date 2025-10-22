/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:27:10 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/10 21:27:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook my_contact;
    std::string command;

    std::cout 
        << "\033[2J\033[1;1H"
        << "       WELCOME TO AWESOME PHONEBOOK APP       \n"
        << "==============================================\n"
        << "* Can store max of 8 contacts (entry 0 - 7)   \n"
        << "* Type these commands in the prompt >         \n"
        << "\n"
        << "COMMAND |   ACTION                            \n"
        << "--------|-------------------------------------\n"
        << "ADD     |   save new contact                  \n"
        << "SEARCH  |   select a contact to be displayed  \n"
        << "EXIT    |   quit and all contacts lost        \n"
        << "\n" << std::endl;
    
    while(1)
    {
        std::cout << "\n\033[32mprompt > \033[0m";
        std::getline(std::cin, command);

        if      (command == "ADD")     my_contact.add();
        else if (command == "SEARCH")  my_contact.search();
        else if (command == "EXIT")    break;
        else
        {
            std::cout
                << "Invalid command. Try again...\n"
                << std::endl;
        }
    }
    return (0);
}