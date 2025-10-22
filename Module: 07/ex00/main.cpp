/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:12:41 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 17:55:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void test_swap()
{
    std::cout << YELLOW
         << "\nTest template: Swapping values between arg"
         << "\n==========================================\n"
         << RESET;

    char a = 'a';
    char b = 'b';
    swap<char>(a, b);
    std::cout << "a = " << a << "\n"
         << "b = " << b << "\n\n";

    int i1 = 10;
    int i2 = 33;
    swap<int>(i1, i2);
    std::cout << "i1 = " << i1 << "\n"
         << "i2 = " << i2 << "\n\n";

    float f1 = 3.123;
    float f2 = 15.6;
    swap<float>(f1, f2);
    std::cout << "f1 = " << f1 << "\n"
         << "f2 = " << f2 << "\n\n";
}

void test_min()
{
    std::cout << YELLOW
         << "\nTest template: Compare 2 arg and return the smallest value"
         << "\n==========================================================\n"
         << RESET;

    char a = 'a';
    char b = 'A';
    std::cout << a << " vs " << b << ", smallest is = " << min<char>(a, b) << "\n\n";

    int i1 = 33;
    int i2 = 33;
    std::cout << i1 << " vs " << i2 << ", smallest is = " << min<int>(i1, i2) << "\n\n";

    float f1 = 3.123;
    float f2 = 15.6;
    std::cout << f1 << " vs " << f2 << ", smallest is = " << min<float>(f1, f2) << "\n\n";
}

void test_max()
{
    std::cout << YELLOW
         << "\nTest template: Compare 2 arg and return the biggest value"
         << "\n==========================================================\n"
         << RESET;

    char a = 'a';
    char b = 'A';
    std::cout << a << " vs " << b << ", biggest is = " << max<char>(a, b) << "\n\n";

    int i1 = 33;
    int i2 = 33;
    std::cout << i1 << " vs " << i2 << ", biggest is = " << max<int>(i1, i2) << "\n\n";

    float f1 = 3.123;
    float f2 = 15.6;
    std::cout << f1 << " vs " << f2 << ", biggest is = " << max<float>(f1, f2) << "\n\n";
}

int main()
{
    // test_swap();
    // test_min();
    // test_max();

    int a = 2;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
