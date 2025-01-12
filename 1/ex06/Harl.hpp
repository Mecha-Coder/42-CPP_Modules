/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:24:53 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/07 10:44:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <map>

class Harl
{
    private:
        std::string lvl[5];
        void (Harl::*ft_ptr[5])();
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void _switch(void);

    public:
        Harl();
        void complain(std::string level);
};

#endif
