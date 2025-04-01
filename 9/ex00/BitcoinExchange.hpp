/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:00:10 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/31 23:00:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <iomanip>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef std::string str;
typedef std::map<std::string, double> myMap;
typedef std::ifstream File;

enum Error {
    BAD_ARG,
    RD_FILE_FAIL,
    BAD_INPUT,
    BAD_FORMAT,
    BELOW_MIN,
    ABOVE_MAX,
    NO_DATA,
};

bool isDate(const str &s);
bool isValue(const str &s);
bool err_msg(Error code, str msg="");
str trim(const str &s);

#endif