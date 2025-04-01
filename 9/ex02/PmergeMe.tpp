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

template <typename Container1, typename Container2, typename Container3>
bool init_and_fill(int ac, char **av, Container1 &a, Container2 &b, Container3 &c)
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
        c.push_back(static_cast<int>(num));
    }
    return true;
}

template <typename Container>
void showNumber(const Container &a)
{
    for (typename Container::const_iterator i = a.begin(); i != a.end(); i++)
        std::cout << *i << " ";
    std::cout << "\n";
}