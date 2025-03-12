/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:24:57 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/10 20:24:57 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream> 

class Contact 
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_no;
        std::string dark_secret;
    
    public:
        Contact();
        std::string f_name(void) const;
        std::string l_name(void) const;
        std::string n_name(void) const;
        std::string phone(void) const;
        std::string secret(void) const;
        void add(std::string info[]);
};

#endif