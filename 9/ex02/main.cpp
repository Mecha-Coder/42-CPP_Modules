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

// Ford-Johnson Algorithm Breakdown:

/* Chat-GPT
1) Pair and Sort:
- Split the input into pairs of elements.
- Sort each pair (e.g., compare elements in each pair and swap if necessary).

2) Recursive Sorting:
- Collect the larger element from each sorted pair into a new list.
- Recursively sort this new list of larger elements using the same algorithm.

3) Insert Smaller Elements:
- Insert the smaller elements (from the original pairs) into the now-sorted list of larger elements using binary insertion (binary search to find the correct position, minimizing comparisons).

4) Handle Odd Elements:
- If the input size is odd, the unpaired element is inserted at the end using binary insertion.
*/

/* DeepSeek
1. Group Elements into Pairs

- Pair adjacent elements and compare them.
- Swap within pairs so that the smaller element is first.
- If the list has an odd length, leave the last element unpaired (called the "leftover").

Example:
Input: [5, 2, 9, 1, 7, 4, 8, 3, 6, 10, 12, 11, 13]
Pairs: (2,5), (1,9), (4,7), (3,8), (6,10), (11,12)
Leftover: 13

2. Extract and Recursively Sort the Larger Elements

- From each pair, take the second (larger) element to form a new list.
- Recursively sort this new list using the same algorithm.

Example:
Larger elements: [5, 9, 7, 8, 10, 12]
Recursively sort [5, 9, 7, 8, 10, 12]

3.  Insert the Smaller Elements

- The smaller elements (from the original pairs) must be inserted into the main chain.
- Insertion order follows a special sequence to minimize comparisons (based on Jacobsthal numbers).
- Binary insertion is used to place each element.

Example:
Smaller elements to insert: [2, 1, 4, 3, 6, 11] (partners of [5,9,7,8,10,12]).
*/

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    Vector a;
    //List b;
    Deque c;
    clock_t start, end;
    if (!init_and_fill(ac, av, a, c)) 
        return EXIT_FAILURE;
    
    std::cout << YELLOW "\nVector container\n================\n" RESET
              << GREEN "Before :\n" RESET; showNumber(a);
    start = clock();
    Ford_John_Sort(a);
    end = clock();
    std::cout << RED "\nAfter  : \n" RESET; showNumber(a);
    process_time(start, end, a.size());
   

    // std::cout << YELLOW "\nList container\n================\n" RESET
    //           << GREEN "Before :\n" RESET; showNumber(b); 
    // start = clock();
    // Ford_John_Sort(b);
    // end = clock();
    // std::cout << RED "\nAfter  : \n" RESET; showNumber(b);
    // process_time(start, end, b.size());

    std::cout << YELLOW "\nDeque container\n================\n" RESET
              << GREEN "Before :\n" RESET; showNumber(c); 
    start = clock();
    Ford_John_Sort(c);
    end = clock();
    std::cout << RED "\nAfter  : \n" RESET; showNumber(c);
    process_time(start, end, c.size());
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
