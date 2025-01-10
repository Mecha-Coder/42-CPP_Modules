/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:24:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/07 16:50:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout
        << "[DEBUG]\n"  
        << "I love having extra bacon for my 7XL-double-"
        << "cheese-triple-pickle-special-ketchup burger. "
        << "I really do!"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "[INFO]\n"
        << "I cannot believe adding extra bacon costs more money. "
        << "You didn’t put enough bacon in my burger! "
        << "If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning(void)
{
    std::cout
        << "[WARNING]\n"
        << "I think I deserve to have some extra bacon for free. "
        << "I’ve been coming for years whereas you started working "
        << "here since last month"
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "[ERROR]\n"
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

Harl::Harl()
{
    _complain["DEBUG"] = &Harl::debug;
    _complain["INFO"] = &Harl::info;
    _complain["WARNING"] = &Harl::warning;
    _complain["ERROR"] = &Harl::error;
}

void Harl::complain(std::string level)
{
    typedef std::map<std::string, void (Harl::*)()>::iterator MapIterator;
    MapIterator i = _complain.find(level);

    if (i != _complain.end())
        (this->*(i->second))();
    else
    {   
        std::cout 
            << "BLAH BLAH BLAH..." << std::endl;
    }
}
