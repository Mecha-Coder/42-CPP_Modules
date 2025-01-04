/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_phonebook.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:31:46 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/04 16:18:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Contact.hpp"
#include "./include/PhoneBook.hpp"

void add_contact(PhoneBook my_contact);
void view_contact(PhoneBook my_contact);

#define TRUE 1
#define FALSE 0
#define WORD 11
#define PHONE 22

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
        << "\n\n" << std::endl;
    
    while(1)
    {
        std::cout << "prompt > ";
        std::cin >> command; 

        if      (command == "ADD")     add_contact(my_contact);
        else if (command == "SEARCH")  view_contact(my_contact);
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


int valid_input(std::string &data, int type)
{
    int i;
    
    i = -1;
    while (data[++i])
    {
        if (type == WORD && !isalpha(data[i]) && data[i] != ' ')
            return (FALSE);
        else if (type == PHONE && !isdigit(data[i]) && data[i] != '-')
            return (FALSE);
    }
    return (TRUE);
}

std::string get_info(const std::string &prompt, int type)
{
    std::string input;
   
    while (1)
    {
        std::cout << prompt;
        std::cin >> input;

        if (valid_input(input, type))
            break;
        else
            std::cout << "Invalid input. Try again" << std::endl;
    }
    return (input);
}

void add_contact(PhoneBook my_contact)
{
    std::string info[5];   
    std::cout << "Please enter new contact info\n" << std::endl;
    
    info[0] = get_info("First Name    : ", WORD);
    info[1] = get_info("Last Name     : ", WORD);
    info[2] = get_info("Nickname      : ", WORD);
    info[3] = get_info("Phone number  : ", PHONE);
    info[4] = get_info("Darkest secret: ", WORD);

    my_contact.add(info);
}

void view_contact(PhoneBook my_contact)
{
    int input;

    std::cout << "Please enter which entry to view\n" << std::endl;

    while (1)
    {
        std::cout << "Enter entry > ";
        std::cin >> input;

        if (!input)
        {
            std::cout << "Invalid entry" << std::endl;
            break;
        }
        else
            my_contact.search(input);
    }
    
}
