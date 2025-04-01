/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:22:34 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/30 12:22:34 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <stack>
#include <deque>
#include <iostream>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;

    iterator begin(){return this->c.begin();}
    iterator end(){return this->c.end();} 
};

#endif