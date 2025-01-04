/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:00:43 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/04 14:53:28 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Contact.hpp"

#define CONTACT_MAX 8

class PhoneBook
{
    private:
        int current;
        Contact list[CONTACT_MAX]; 

    public:
        PhoneBook() : current(0) {} 
        
        void add(std::string info[]);
        void search(int entry);
};

#endif