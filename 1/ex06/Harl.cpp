/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:24:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/07 16:33:38 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level { DEBUG, INFO, WARNING, ERROR };

Harl::Harl()
{
    Complain.insert(std::make_pair("DEBUG", &Harl::debug));
    Complain.insert(std::make_pair("INFO", &Harl::info));
    Complain.insert(std::make_pair("WARNING", &Harl::warning));
    Complain.insert(std::make_pair("ERROR", &Harl::error));
}

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

void Harl::complain(std::string level)
{
    Level lvl;

    try
    {
        lvl = Complain.at(level);
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    switch (lvl) 
    {
        case DEBUG: debug(); [[fallthrough]]; 
        case INFO:  info(); [[fallthrough]]; 
        case WARNING: warning();[[fallthrough]]; 
        case ERROR:  error();
        break;
    }
}

