/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:58:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/27 15:58:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//=============================================================================
// Constructor & Destructor
//=============================================================================

template <typename T>
Array<T>::Array()
{
    Arr = NULL;
    Size = 0;
    std::cout << "Default CT\n";
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    if (n == 0)
        throw std::invalid_argument("Can't instantiate with 0");
    Arr = new T[n]();
    Size = n;
}

template <typename T>
Array<T>::Array (const Array &obj)
{
    Size = obj.Size;
    Arr = new T[Size];
    for (int i=0; i < Size; i++)
        Arr[i] = obj.Arr()[i];
}

template <typename T>
Array<T>::~Array()
{
    if (Arr) {delete[] Arr;}
}

//=============================================================================
// Overload operator
//=============================================================================

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj)
{
    if (this != &obj)
    {
        delete[] Arr;
        Size = obj.Size;
        Arr = new T[Size];
        for (int i=0; i < Size; i++)
            Arr[i] = obj.Arr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= Size)
        throw std::out_of_range("Index out of bounds");
    return Arr[i];
}

//=============================================================================
// Getter & Setter
//=============================================================================

template <typename T>
unsigned int Array<T>::getSize() const {return Size;}