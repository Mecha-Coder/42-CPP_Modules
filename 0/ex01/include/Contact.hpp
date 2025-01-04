/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:08:23 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/04 09:43:59 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact 
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_no;
        std::string dark_secret;
        
        Contact() : 
            first_name(""), 
            last_name(""),
            nick_name(""), 
            phone_no(""),
            dark_secret("") 
            {}
};

#endif