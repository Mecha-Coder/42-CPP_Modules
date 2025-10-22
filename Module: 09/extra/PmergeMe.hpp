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

#define COUT std::cout 
#define CERR std::cerr

typedef std::vector<int> Vector;
typedef std::deque<int> Deque;

typedef std::vector<std::pair<int, int> > VecPair;
typedef std::vector<std::pair<int, int> > DeqPair;

enum Error {
    BAD_ARG,
    NOT_NUM,
    NUM_OUT_RNG,
};

bool err_msg(Error code);
bool isNumber(const char *s);
void Ford_John_Sort(Deque &main);
void Ford_John_Sort(Vector &main);
void process_time(clock_t start, clock_t end, size_t size);

template <typename Container>
void showNumber(const Container &a);

template <typename C1, typename C2>
bool init_and_fill(int ac, char **av, C1 &a, C2 &b);

template <typename Container>
void run_sorting(Container &c);

#include "PmergeMe.tpp"

#endif