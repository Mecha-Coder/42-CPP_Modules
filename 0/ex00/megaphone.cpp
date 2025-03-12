/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:20:40 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/04 09:35:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cin, cout, endl
#include <string>  // concatenate (+ +=), comparison, finding substr, len
#include <cctype>  // touppper(), isdigit()

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int ac, char **av)
{
    int i;
    std::string s;

    if (ac == 1)
        s = DEFAULT;
    else
    {
        i = 0;
        while (av[++i])
            s += av[i];
        i = -1;
        while (s[++i])
            s[i] = toupper(s[i]);
    }
    std::cout << s << std::endl;
}