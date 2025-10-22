/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:43:45 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/10 20:43:45 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> //cin, cout
#include <iomanip>  // format output std::right
#include <string>   // String manipulation -> std::getline 
#include <cctype>   // isdigit(), isalpha(), isspace()
#include "Contact.hpp"

#define CONTACT_MAX 8
#define TRUE 1
#define FALSE 0
#define WORD 11
#define PHONE 22

class PhoneBook
{
    private:
        int current;
        Contact list[CONTACT_MAX]; 

    public:
        PhoneBook();
        void add(void);
        void search(void);
};

#endif