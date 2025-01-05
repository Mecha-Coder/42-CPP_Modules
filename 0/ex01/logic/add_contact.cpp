/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:17:09 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/05 10:17:09 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/app.hpp"

int valid_input(const std::string &s, int type);
std::string get_info(const std::string &prompt, int type);

void add_contact(PhoneBook &my_contact)
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

std::string get_info(const std::string &prompt, int type)
{
    std::string input;
   
    while (1)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input != "" && valid_input(input, type))
            break;
        else
            std::cout << "Invalid input. Try again\n" << std::endl;
    }
    return (input);
}

int valid_input(const std::string &s, int type)
{
    int i;
    
    i = -1;
    while (s[++i])
    {
        if (type == WORD && !isalpha(s[i]) && s[i] != ' ')
            return (FALSE);
        else if (type == PHONE && !isdigit(s[i]) && s[i] != '-')
            return (FALSE);
    }
    return (TRUE);
}

/* Prompt input until get correct data
int main()
{
    int i = -1;
    int size = 5;
    std::string info[5];

    info[0] = get_info("First Name    : ", WORD);
    info[1] = get_info("Last Name     : ", WORD);
    info[2] = get_info("Nickname      : ", WORD);
    info[3] = get_info("Phone number  : ", PHONE);
    info[4] = get_info("Darkest secret: ", WORD);
    
    std::cout << "\n=======================" << std::endl;
    while (++i < size)
        std::cout << info[i] << std::endl;
}
*/

/* Check valid_input
int main()
{
    std::cout << "WORD\n=======\n"
        << valid_input("Jason", WORD) << '\n'
        << valid_input("Selau Kumar Paul", WORD) << '\n'
        << valid_input("I don't know", WORD) << '\n'
        << valid_input("Wonderful!", WORD) << '\n'
        << valid_input("Great day, sir", WORD) << '\n'
        << valid_input("Yes 123", WORD) << '\n'
        << std::endl;

    std::cout << "\nPHONE\n=======\n"
        << valid_input("04-4901265", PHONE) << '\n'
        << valid_input("6011-26671880", PHONE) << '\n'
        << valid_input("12344123", PHONE) << '\n'
        << valid_input("1234-abc", PHONE) << '\n'
        << valid_input("Nice day", PHONE) << '\n'
        << valid_input("**!!LOLO", PHONE) << '\n'
        << std::endl;
}
*/