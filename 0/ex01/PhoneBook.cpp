/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:52:36 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/03 21:52:36 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_phonebook.hpp"

void PhoneBook::add(const std::string& name, const std::string& phone_no)
{
    if (current == CONTACT_MAX) 
        current = 0; 
    list[current].name = name;
    list[current].phone_no = phone_no;
    current++;
}

void PhoneBook::show()
{
    int i;
    i = 0;
    while (list[i].name != "" && list[i].phone_no != "") {
        std::cout << list[i].name << " ---> ";
        std::cout << list[i].phone_no << std::endl;
        std::cout << "===============================" << std::endl;
        i++;
    }
}