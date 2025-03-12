/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:47:35 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/10 20:47:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int is_empty(const std::string &s)
{
    int i;
    
    i = -1;
    while (s[++i])
    {
        if (!isspace(s[i]))
            return (FALSE);
    }
    return (TRUE);
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

std::string get_info(const std::string &prompt, int type)
{
    std::string input;
   
    while (1)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!is_empty(input) && valid_input(input, type))
            break;
        else
            std::cout << "Invalid input. Try again\n" << std::endl;
    }
    return (input);
}

void print(const std::string& s)
{
    std::cout << std::setw(10)
        << (s.length() > 10 ? s.substr(0, 9) + "." : s) 
        << "|";
}

void print_header(void)
{
    std::cout 
        << "\n"
        << "|     Index|First Name| Last Name|  Nickname|"
        << std::endl;
            
        std::cout 
            << "|----------|----------|----------|----------|" 
            << std::endl;
}

PhoneBook::PhoneBook() : current(0) {}

void PhoneBook::add(void)
{
    std::string info[5];   
    std::cout << "Please enter new contact info\n" << std::endl;
    
    info[0] = get_info("First Name    : ", WORD);
    info[1] = get_info("Last Name     : ", WORD);
    info[2] = get_info("Nickname      : ", WORD);
    info[3] = get_info("Phone number  : ", PHONE);
    info[4] = get_info("Darkest secret: ", WORD);

    if (current == CONTACT_MAX)
        current = 0;
    if (list[current].f_name() != "")
        std::cout << "* Override entry " << current << std::endl;

    list[current].add(info);

    std::cout << "Contact successfully saved in entry " << current << std::endl;
    current++;
}

void PhoneBook::search(void)
{
    std::string input;
    int entry;

    std::cout << "Please enter which entry to view\n" << std::endl;

    while (1)
    {
        std::cout << "Enter entry : ";
        std::getline(std::cin, input);

        if (input.length() != 1 || input[0] < '0' || input[0] > '7')
        {
            std::cout << "Invalid entry" << std::endl;
            break;
        }
        else
        {
            entry = input[0] - '0';
            if (list[entry].f_name() == "")
                std::cout << "Entry '" << entry <<"' is empty\n" << std::endl;
            else
            {
                std::string s_entry(1, entry + '0');
                print_header();
                std::cout << std::right << "|";
                    print(s_entry);
                    print(list[entry].f_name());
                    print(list[entry].l_name());
                    print(list[entry].n_name());
                std::cout << "\n" <<std::endl;
            }
        }
    }
}
