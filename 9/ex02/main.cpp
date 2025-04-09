/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:03:42 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 14:03:42 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    Vector a; Deque b;
   
    if (!init_and_fill(ac, av, a, b))
        return EXIT_FAILURE;
    
    COUT << YELLOW "\nDeque container \n================\n" RESET ; run_sorting(b);
    COUT << YELLOW "\nVector container\n================\n" RESET ; run_sorting(a);
}

/*Test case

OK 
Single digit
=============
./PmergeMe 2147483647
./PmergeMe 0
./PmergeMe 1
./PmergeMe 22
./PmergeMe 3 5 9 7 4
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
./PmergeMe `shuf -i 1-100000 -n 10000 | tr "\n" " "`
./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

./PmergeMe 2 12 4 2 5 8 0 2 3

./PmergeMe 53 98 60 88 92 57 40 97 15 9 84 64 50 44 52 86 75 18 3 79 76 48 38 78 5

./PmergeMe 14 93 98 15 96 2147483647 39 22 51 63 81 61 64 6 57 23 86 1 36 19 48 30 60 91 85 27 10 94 2 17 79 45 55 29 33 53 7 8 49 31 5 100 52 73 95 42 82 35 38 58 84 21 62 16 65 77 4 97 28 9 88 40 87 66 69 25 67 75 59 32 43 44 41 80 13 24 76 90 54 12 71 72 37 99 46 74 78 92 3 47 70 56 68 89 11 18 20 50 26 34 83

KO
./PmergeMe "-1" "2"
./PmergeMe -2147483648
./PmergeMe
./PmergeMe 2147483999
./PmergeMe -2147483999
./PmergeMe -21474839995
./PmergeMe +
./PmergeMe -
./PmergeMe 999999999999999999999999
./PmergeMe abc
./PmergeMe -5a
./PmergeMe "    "
./PmergeMe ""
./PmergeMe 3 5 9 7 4 -2
*/
