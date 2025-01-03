/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_phonebook.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:31:46 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/03 22:31:46 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook my_contact;

    std::cout << "\n1st Entry\n" <<  std::endl;

    my_contact.add("Jason", "011-26671880");
    my_contact.show();
    
    std::cout << "\n2nd Entry\n" <<  std::endl;

    my_contact.add("Lul",     "+6012-345-6789");
    my_contact.add("Alia",    "+6013-456-7890");
    my_contact.add("Siti",    "+6014-567-8901");
    my_contact.add("John",    "+6016-678-9012");
    my_contact.add("Kenneth", "+6017-789-0123");
    my_contact.add("Amirul",  "+6019-890-1234");
    my_contact.add("Harry",   "+6012-901-2345");
    my_contact.show();

    std::cout << "\n3th Entry\n" <<  std::endl;

    my_contact.add("Lyara", "+6014-123-4567");
    my_contact.add("Adya",  "+6016-234-5678");
    my_contact.show();
    
    std::cout << "\n4th Entry\n" <<  std::endl;

    my_contact.add("Leon",    "+6013-012-3456");
    my_contact.show();
}