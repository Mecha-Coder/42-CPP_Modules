/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:00:43 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/03 23:00:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include "Contact.hpp"

#define CONTACT_MAX 8

class PhoneBook
{
    private:
        int current;
        Contact list[CONTACT_MAX]; 

    public:
        PhoneBook() : current(0) {} 
        void add();
};

#endif