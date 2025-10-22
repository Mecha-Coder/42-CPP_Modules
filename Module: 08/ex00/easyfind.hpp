/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 21:02:06 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 21:04:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

template <typename C>
bool easyfind(C &a, int b);

template <typename C>
void showNumber(C &a);

#include "easyfind.tpp"

#endif