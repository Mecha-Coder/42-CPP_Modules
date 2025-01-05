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

#include "../include/app.hpp"

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

/* 
Dummy data
==========
1. 
John 
Doe 
Johnny 
012-3456789 
I once ate an entire pizza in one sitting

2. 
Jane 
Smith 
Janey
017-9876543
I secretly love reality TV

3. 
David 
Lee 
Dave 
019-1234567 
Im afraid of clowns

4. 
Sarah 
Jones 
Sally 
014-7654321 
I once sang karaoke in public and sounded terrible

5. 
Michael 
Brown 
Mike 
016-8765432
I still sleep with a teddy bear

6. 
Emily 
Davis 
Em 
011-2345678 
I can whistle

7. 
Daniel 
Moore 
Dan 
013-5432109 
Im secretly a fan of country music

8. 
Olivia 
Wilson 
Liv 
018-9012345 
I once tripped and fell in front of a crowd

9. 
James 
Taylor 
Jim 
019-6789012 
I can tell a joke to save my life

10. 
Chloe 
Anderson 
Chloe 
017-4321098 
Im afraid of heights
*/