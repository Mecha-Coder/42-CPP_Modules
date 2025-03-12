/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:07 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/08 19:19:07 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;            // Default constructor called
    std::cout << "---------------------------------------------" << std::endl;
    Fixed const b(10);  // Int constructor called
    std::cout << "---------------------------------------------" << std::endl;
    Fixed const c(42.42f); // Float constructor called
    std::cout << "---------------------------------------------" << std::endl;
    Fixed const d(b);      // Copy constructor called
    std::cout << "---------------------------------------------" << std::endl;

    a = Fixed(1234.4321f); // Copy assignment operator called
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    return 0;
}


/* Output
Default constructor called
-------------------------------------------
Int constructor called
------------------------------------------
Float constructor called
------------------------------------------
Copy constructor called
------------------------------------------
Copy assignment operator called <---- // Not suppose to be here
Float constructor called
Copy assignment operator called
Destructor called
------------------------------------------
a is 1234.43
b is 10
c is 42.4219
d is 10
------------------------------------------
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
------------------------------------------
Destructor called
Destructor called
Destructor called
Destructor called
*/