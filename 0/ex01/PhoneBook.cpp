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

void PhoneBook::add()
{
    if (current == CONTACT_MAX) 
        current = 0; 
    list[current].name = name;
    list[current].phone_no = phone_no;
    current++;
}