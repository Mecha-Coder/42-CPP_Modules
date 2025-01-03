/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:08:23 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/03 23:08:23 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact 
{
    public:
        std::string f_name;
        std::string l_name;
        std::string nickname;
        std::string phone_no;
        std::string dark_secret;
        
        Contact() : 
            f_name(""), 
            l_name(""),
            nickname(""), 
            phone_no(""),
            dark_secret("") 
            {}
};

#endif