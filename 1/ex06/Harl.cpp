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
        << "cheese-triple-pickle-special-ketchup burger.\n"
        << "I really do!\n"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "[INFO]\n"
        << "I cannot believe adding extra bacon costs more money.\n"
        << "You didn’t put enough bacon in my burger!\n"
        << "If you did, I wouldn’t be asking for more!\n"
        << std::endl;
}

void Harl::warning(void)
{
    std::cout
        << "[WARNING]\n"
        << "I think I deserve to have some extra bacon for free.\n"
        << "I’ve been coming for years whereas you started working here since last month.\n"
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "[ERROR]\n"
        << "This is unacceptable!\n"
        << "I want to speak to the manager now.\n"
        << std::endl;
}

Harl::Harl()
{
    _complain["DEBUG"] = &Harl::debug;
    _complain["INFO"] = &Harl::info;
    _complain["WARNING"] = &Harl::warning;
    _complain["ERROR"] = &Harl::error;
    _complain["SWITCH"] = &Harl::error;
}

void Harl::complain(std::string level)
{
    typedef std::map<std::string, void (Harl::*)()>::iterator MapIterator;
    MapIterator i = _complain.find(level);

    if (i == _complain.end())
    {
         std::cout
                << "[ Probably complaining about insignificant problems ]\n"
                << std::endl;
    }
    else
    {   
        switch (level[0])
        {
            case 'D':   debug(); /* fallthrough */
            case 'I':    info(); /* fallthrough */
            case 'W': warning(); /* fallthrough */
            case 'E':   error();
        }
    }
}
