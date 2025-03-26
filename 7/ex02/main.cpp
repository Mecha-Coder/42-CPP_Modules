/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:56:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 23:29:33 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array {
    T *Arr;
    unsigned int Size;
public:
    Array()
    {
        Arr = new T();
        Size = 0;
    }

    Array(unsigned int n)
    {
        if (n == 0)
            throw std::invalid_argument("x cannot be zero");
        Arr = new T[n];
        Size = n;
    }

    Array (const Array &obj)
    {
        Size = obj.getSize();

        if (!Size)
        {
            Arr = new T()
            *Arr = *(obj.Arr); 
        } 
        else
        {
            Arr = new T[Size];
            for (int i=0; i < Size; i++)
                Arr[i] = obj.Arr[i]
        }
    }

    Array &operator=(const Array &obj)
    {
        if (this != &obj)
        {
            if (!Size)
            {
                Arr = new T()
                *Arr = *(obj.Arr); 
            } 
            else
            {
                Arr = new T[Size];
                for (int i=0; i < Size; i++)
                    Arr[i] = obj.Arr[i]
            }
        }
        return *this;
    }

    T *getArray() const {return Arr;}
    unsigned int getSize() const {return Size;}
};