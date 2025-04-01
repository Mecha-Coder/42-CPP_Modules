/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:47 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 14:03:47 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <climits>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef std::string str;
typedef std::vector<int> Vector;
typedef std::list<int> List;
typedef std::deque<int> Deque;

enum Error {
    BAD_ARG,
    NOT_NUM,
    NUM_OUT_RNG,
};

bool err_msg(Error code);
bool isNumber(const char *s);
void Ford_John_Sort(List &list);
void Ford_John_Sort(Vector &vector);
void Ford_John_Sort(Deque &deq);
void process_time(clock_t start, clock_t end, size_t size);

template <typename Container1, typename Container2, typename Container3>
bool init_and_fill(int ac, char **av, Container1 &a, Container2 &b, Container3 &c);

template <typename Container>
void showNumber(const Container &a);

#include "PmergeMe.tpp"

#endif