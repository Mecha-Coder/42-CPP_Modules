/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:08:19 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 19:07:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void test()
{
    int* arr1 = new int[5];   // Uninitialized elements (garbage values)
    int* arr2 = new int[5](); // Zero-initialized elements

    std::cout << arr1[0] << " " << arr1[3] << "\n";
    std::cout << arr2[0] << " " << arr2[3] << "\n";

    delete[] arr1;
    delete[] arr2;
}

void test_with_int()
{
    std::cout << YELLOW
    << "\nTest constructor"
    << "\n================\n"
    << RESET;

    Array<int> a;
    Array<int> b(5);
    Array<int> c(3);
    // Array<float> c(b); // <---Can't copy need to be the same type
    
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size b: " << b.getSize() << " | " ; iterate(b);
    std::cout << "Size c: " << c.getSize() << " | " ; iterate(c);
    
    //------------------------------------------------------------------

    std::cout << YELLOW
    << "\nTest copy assignment and ensure both are separate copy"
    << "\n=======================================================\n"
    << RESET;

    b = a;
    a = c;
    a[0] = 4;  // testing index access using subscript operator[]
    a[1] = 3;
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size b: " << b.getSize() << " | " ; iterate(b);
    std::cout << "Size c: " << c.getSize() << " | " ; iterate(c);

    //------------------------------------------------------------------

    std::cout << YELLOW
    << "\nTest copy constructor and ensure both are separate copy"
    << "\n=======================================================\n"
    << RESET;
    
    Array<int> d(a);
    d[0] = 5;
    d[1] = 5;
    d[2] = 5;
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size d: " << d.getSize() << " | " ; iterate(d);

    //------------------------------------------------------------------

    std::cout << YELLOW
    << "\nThrow exception if out of bound"
    << "\n================================\n"
    << RESET;

    try { d[-1] = 77;}
    catch(const std::exception &e) 
    {std::cout << RED "Exception caught: " RESET << e.what() << "\n";}

    try { d[10] = 77;}
    catch(const std::exception &e) 
    {std::cout << RED "Exception caught: " RESET << e.what() << "\n";}
}

void test_with_string()
{
    std::cout << YELLOW
    << "\nTest constructor"
    << "\n================\n"
    << RESET;

    Array<str> a;
    Array<str> b(5);
    Array<str> c(3);
    
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size b: " << b.getSize() << " | " ; iterate(b);
    std::cout << "Size c: " << c.getSize() << " | " ; iterate(c);
    
    //------------------------------------------------------------------

    std::cout << YELLOW
    << "\nTest copy assignment and ensure both are separate copy"
    << "\n=======================================================\n"
    << RESET;

    b = a;
    a = c;
    a[0] = "Hello";  // testing index access using subscript operator[]
    a[1] = "World";
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size b: " << b.getSize() << " | " ; iterate(b);
    std::cout << "Size c: " << c.getSize() << " | " ; iterate(c);

    //------------------------------------------------------------------

    std::cout << YELLOW
    << "\nTest copy constructor and ensure both are separate copy"
    << "\n=======================================================\n"
    << RESET;
    
    Array<str> d(a);
    d[0] = "Nice";
    d[1] = "To";
    d[2] = "See you";
    std::cout << "Size a: " << a.getSize() << " | " ; iterate(a);
    std::cout << "Size d: " << d.getSize() << " | " ; iterate(d);

    //------------------------------------------------------------------
    
    std::cout << YELLOW
    << "\nThrow exception if out of bound"
    << "\n================================\n"
    << RESET;

    try { d[-1] = 77;}
    catch(const std::exception &e) 
    {std::cout << RED "Exception caught: " RESET << e.what() << "\n";}

    try { d[10] = 77;}
    catch(const std::exception &e) 
    {std::cout << RED "Exception caught: " RESET << e.what() << "\n";}
}

int main()
{
    // test();
    test_with_int();
    //test_with_string();
}
