/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:28:20 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 15:28:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

typedef std::string str;

class Form
{
    str const	_name;
    bool		_signed;
    int const	_signGrade;
    int const	_executeGrade;
    static const int	maxGrade = 1;
    static const int	minGrade = 150;  
};

