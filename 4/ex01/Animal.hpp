/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:46:48 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/18 20:18:56 by jpaul            ###   ########.fr       */
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
        Animal();
        Animal(const str& type);
        Animal(const Animal& other);
        Animal& operator=(const Animal &other);
        virtual ~Animal();
    
        virtual void makeSound() const;
        str getType() const;
        
       virtual void setIdea(int i, const str& idea) = 0;
       virtual str getIdea(int i) const = 0;
};

#endif