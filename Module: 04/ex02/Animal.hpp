/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:46:48 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/15 15:46:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Animal
{
    protected:
        str type;

    public:
        virtual Animal& operator=(const Animal &other) = 0;
        virtual ~Animal();

        str getType() const;
        virtual void makeSound() const = 0;
        virtual void setIdea(int i, const str& idea) = 0;
        virtual str getIdea(int i) const = 0;
};

#endif