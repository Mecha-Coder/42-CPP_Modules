/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:18:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/05 10:18:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_HPP
#define APP_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"

#define TRUE 1
#define FALSE 0
#define WORD 11
#define PHONE 22

void add_contact(PhoneBook &my_contact);
void view_contact(PhoneBook &my_contact);

#endif