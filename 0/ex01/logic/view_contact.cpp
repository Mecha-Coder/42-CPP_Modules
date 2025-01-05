/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_view.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:22:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/05 10:22:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/app.hpp"

void view_contact(PhoneBook &my_contact)
{
    std::string input;

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
            my_contact.search(input[0] - '0');
    }
}