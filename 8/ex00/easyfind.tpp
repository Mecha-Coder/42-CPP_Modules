/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:56:05 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 22:56:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename C>
bool easyfind(C &a, int b)
{
    typename C::iterator i = std::find(a.begin(), a.end(), b);
    return (*i == b);
}

template <typename C>
void showNumber(C &a)
{
    typename C::iterator i = a.begin();
    while (i != a.end())
        std::cout << *(i++) << " ";
    std::cout << "\n";
}