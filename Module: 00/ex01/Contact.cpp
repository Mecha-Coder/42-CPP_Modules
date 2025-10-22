/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:26:01 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/10 20:26:01 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() :
    first_name(""), 
    last_name(""),
    nick_name(""), 
    phone_no(""),
    dark_secret("") 
{}

std::string Contact:: f_name(void) const {return (first_name);}
std::string Contact:: l_name(void) const {return (last_name);}
std::string Contact:: n_name(void) const {return (nick_name);}
std::string Contact:: phone(void) const {return (phone_no);}
std::string Contact:: secret(void) const {return (dark_secret);}

void Contact::add(std::string info[])
{
    first_name  = info[0];
    last_name   = info[1];
    nick_name   = info[2];
    phone_no    = info[3];
    dark_secret = info[4];
}