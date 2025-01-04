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


/* Requirement

Arg_no :                                    1
Input  : ./megaphone "shhhhh... I think the students are asleep..."
Output :              SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

Arg_no :                1     2                      3
Input  : ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
Output :             DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

Arg_no :      0
Input  : ./megaphone
Output :              * LOUD AND UNBEARABLE FEEDBACK NOISE *

*/