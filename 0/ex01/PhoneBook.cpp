/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:52:36 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/04 16:16:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/PhoneBook.hpp"

void print(std::string& s)
{
    std::cout 
        << std::setw(10)
        << (s.length() > 10 ? s.substr(0, 9) + "." : s) 
        << "|";
}

void PhoneBook::add(std::string info[])
{
    if (current == CONTACT_MAX)
        current = 0;

    if (list[current].first_name != "")
    {
        std::cout 
            << "Override entry" << current 
            << std::endl;
    }
    
    list[current].first_name  = info[0];
    list[current].last_name   = info[1];
    list[current].nick_name   = info[2];
    list[current].phone_no    = info[3];
    list[current].dark_secret = info[4];
    
    std::cout 
        << "Contact successfully saved in entry" << current 
        << std::endl;
    
    current++;
}

void PhoneBook::search(int entry)
{
    if (entry < 0 || entry >= CONTACT_MAX)
    {    
        std::cout 
            << "Invalid entry range" 
            << std::endl;
    }
    else if (list[entry].first_name == "")
    {    
        std::cout 
            << "Entry " << entry <<" is empty"
            << std::endl;
    }
    else
    {
        std::string s_entry(1, entry + '0');
        std::cout 
            << "\n|"
            << "|     Index|First Name| Last Name|  Nickname|"
            << std::endl;
    
        std::cout 
            << "|----------|----------|----------|----------|" 
            << std::endl;

        std::cout << std::right << "|";
            print(s_entry);
            print(list[entry].first_name);
            print(list[entry].last_name);
            print(list[entry].nick_name);
        std::cout <<std::endl;
    }
}





