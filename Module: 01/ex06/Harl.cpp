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
        << "I’ve been coming for years whereas you started working "
        << "here since last month.\n"
        << std::endl;
}

void Harl::error(void)
{
    std::cout
        << "[ERROR]\n"
        << "This is unacceptable! I want to speak to the manager now.\n"
        << std::endl;
}

void Harl::_switch(void) {}

Harl::Harl()
{
    lvl[0] = "DEBUG"  ; ft_ptr[0] = &Harl::debug;
    lvl[1] = "INFO"   ; ft_ptr[1] = &Harl::info;
    lvl[2] = "WARNING"; ft_ptr[2] = &Harl::warning;
    lvl[3] = "ERROR"  ; ft_ptr[3] = &Harl::error;
    lvl[4] = "SWITCH" ; ft_ptr[4] = &Harl::_switch;
    
}

void Harl::complain(std::string level)
{
    int i = -1;
    while (++i < 5)
    {
        if (lvl[i] == level)
            break;
    }
    switch(i)
    {
        case 0: (this->*ft_ptr[0])();
            //fallthrough
        case 1: (this->*ft_ptr[1])();
            //fallthrough
        case 2: (this->*ft_ptr[2])();
            //fallthrough
        case 3: (this->*ft_ptr[3])();
            //fallthrough
        case 4: (this->*ft_ptr[4])();
            break;
        default:
            std::cout 
                << "[ Probably complaining about insignificant problems ]"
                << std::endl;
        }
}
