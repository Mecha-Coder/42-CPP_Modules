/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 04:26:50 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/02 04:26:50 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C1, typename C2>
bool init_and_fill(int ac, char **av, C1 &a, C2 &b)
{
    long num;

    if (ac < 2) 
        return err_msg(BAD_ARG);
        
    for (int i=1; i < ac; i++)
    {
        if (!isNumber(av[i]))
            return err_msg(NOT_NUM);
        
        num = strtol(av[i], NULL, 10);
        if (num < 0 || num > INT_MAX)
            return err_msg(NUM_OUT_RNG);
        
        a.push_back(static_cast<int>(num));
        b.push_back(static_cast<int>(num));
    }
    return true;
}

template <typename Container>
void showNumber(const Container &a)
{
    typename Container::const_iterator i = a.begin();

    while (i != a.end())
        COUT << *i++ << " ";
    COUT << "\n";
}

template <typename Container>
void run_sorting(Container &c)
{
    clock_t start, end;
    COUT << GREEN "Before :\n" RESET; showNumber(c);
    
    start = clock();
    Ford_John_Sort(c);
    end = clock();
    
    COUT << RED "\nAfter  : \n" RESET; showNumber(c);
    process_time(start, end, c.size());
}