/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:51:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 22:51:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#define ERR1 "Error. filename, s1 & s2 can't be blank"
#define ERR2 "Error. Can't open "
#define ERR3 "Error. Can't open or create output file"

bool is_empty(const std::string& s);
int run(std::string filename, std::string s1, std::string s2);

#endif