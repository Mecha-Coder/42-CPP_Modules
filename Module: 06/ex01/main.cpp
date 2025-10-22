/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:54:10 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 17:40:52 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    // reinterpret_cast (low level)
    // Unrelated pointer types (int* --> char*)
    // pointer to int (void* → uintptr_t)

    //Serializer a // <---- Can't instantiate

    Data s = {true};

    uintptr_t temp1 = Serializer::serialize(&s);
    Data *temp2 = Serializer::deserialize(temp1);

    std::cout << "Address        : " << &s << "\n"
              << "Convert to num : " << temp1 << "\n" 
              << "Revert back    : " << temp2 << "\n"
              << "Compare        : " << ((&s == temp2)? "Same" : "Not same") << "\n";
}
