/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:10:06 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/26 12:10:06 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer:: Serializer(const Serializer &original){(void)original;}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr)
{return reinterpret_cast<uintptr_t>(ptr);}

Data *Serializer::deserialize(uintptr_t raw)
{return reinterpret_cast<Data *>(raw);}
