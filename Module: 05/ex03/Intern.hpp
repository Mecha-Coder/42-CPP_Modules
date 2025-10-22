/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:19:30 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/23 21:19:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    class FormException : public exception
    {public: virtual const char *what() const throw();};

    AForm *makeShrubberyForm(const str &target);
    AForm *makeRobotomyForm(const str &target);
    AForm *makePardonForm(const str &target);

public:
    Intern();
    ~Intern();

    AForm *makeForm(const str &form, const str &target);
};

#endif