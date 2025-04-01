/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:24:13 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/30 12:24:13 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void my_test_case()
{
    MutantStack<int> a;

    a.push(5);
    a.push(6);
    a.push(11);

    for (MutantStack<int>::iterator i=a.begin(); i != a.end(); i++)
        std::cout << *i << ", ";
    std::cout << "\n\n";

    a.push(-2);

    for (MutantStack<int>::iterator i=a.begin(); i != a.end(); i++)
    std::cout << *i << ", ";
    std::cout << "\n\n";

    /*
    The std::stack copy constructor sees MutantStack as a std::stack<int> (because of inheritance).
    It copies only the std::stack part of MutantStack (not any additional methods from MutantStack).
    */
    std::stack<int> temp(a);
    std::cout << "Size: " << temp.size() << " | " << "top value: " << temp.top() << "\n";
}

void pdf_test_case()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "\nCurrent top: " << mstack.top() << std::endl; // Output: 17

    mstack.pop();

    std::cout << "\nSize after pop: " << mstack.size() << std::endl; // Output: 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "\n++it: " << *(++it) << "\n"; // Output: 3
    std::cout << "\n--it: "<< *(--it) << "\n";  // Output: 5
    
    std::cout << "\nPrint stack from bottom to top\n"
              << "-------------------------------\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "\nCopy MutantStack -> actual stack\n"
              << "Top: "  << s.top() << " | Size: " << s.size() << "\n";
}

void normal_list()
{
    std::list<int> mylist;
    
    mylist.push_back(5);
    mylist.push_back(17);
    
    std::cout << "\nCurrent top: " << mylist.back() << std::endl; // Output: 17

    mylist.pop_back();

    std::cout << "\nSize after pop: " << mylist.size() << std::endl; // Output: 1

    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);
    mylist.push_back(0);

    std::list<int>::iterator it = mylist.begin();
    std::list<int>::iterator ite = mylist.end();
    
    std::cout << "\n++it: " << *(++it) << "\n"; // Output: 3
    std::cout << "\n--it: "<< *(--it) << "\n";  // Output: 5
    
    std::cout << "\nPrint list from start to end\n"
              << "-------------------------------\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{
    //my_test_case()
    
    std::cout << YELLOW
    << "\nMutated stack"
    << "\n=============================================\n"
    << RESET;
    pdf_test_case();
    
    std::cout << YELLOW
    << "\nNormal list"
    << "\n=============================================\n"
    << RESET;
    normal_list();
}

