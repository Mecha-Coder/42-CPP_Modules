/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:46:52 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/25 20:02:24 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class ScalarConverter
{
    ScalarConverter();
    ~ScalarConverter();
public:
    static void convert(string s);
};
