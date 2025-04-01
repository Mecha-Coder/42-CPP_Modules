/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 05:09:43 by jpaul             #+#    #+#             */
/*   Updated: 2025/04/01 05:09:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int compute(int a, int b, char c)
{
    switch (c)
    {
        case '+': return (a + b);
        case '-': return (a - b);
        case '*': return (a * b);
        case '/': 
            if (b == 0) std::exit(err_msg(FAIL_COMPUTE));
            return (a / b); 
    }
    return (0);
}

int main(int ac, char **av)
{
    int a, b, result;
    std::stack<int> Stack;
    
    if (ac != 2) return err_msg(BAD_ARG);
    str s = av[1];

    // Loop through the string
    for (size_t i=0; i < s.size(); i++)
    {
        // If digit, convert and put to stack
        if (isdigit(s[i]))
            Stack.push(s[i] - '0');

        // If operator, pop 2 elements (ensure have 2 elements) 
        //  => compute => push back to stack
        else if (isOperator(s[i]))
        {
            if (Stack.size() < 2) 
                return err_msg(FAIL_COMPUTE);
            
            b = Stack.top(); Stack.pop();
            a = Stack.top(); Stack.pop();
            Stack.push(compute(a, b, s[i]));
        }

        else if (s[i] == ' ')  continue;
        else                   return err_msg(BAD_EXPRESS);
    }

    // Validate final result
    if (Stack.empty())
        return err_msg(BAD_EXPRESS);
    
    result = Stack.top(); Stack.pop();
    if (Stack.size())
        return err_msg(FAIL_COMPUTE);

    std::cout << result << "\n";
}

/*
test case
=========

OK
./RPN "2 3 +"               // Output: 5
./RPN "23+"                 // Output: 5
./RPN "0 3 /"               // Output: 0
./RPN "3 4 2 * 15 - / +"    // Output:   ~ 3 + 4 x 2 / (1 - 5) = 1
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" // Output: 42
./RPN "7 7 * 7 -"            // Output: 42
./RPN "1 2 * 2 / 2 * 2 4 - +" // Output: 0
./RPN "3"                    // Output: 3
./RPN "5 2 /"            // Output: 2

KO
./RPN "5 /"
./RPN "3 0 /"
./RPN "    "
./RPN ""
./RPN "+ -"
./RPN "3 4 5"
./RPN "3 +"
./RPN "(1 + 1)"
./RPN "a + b"
./RPN "1.5 + 20.43"
*/