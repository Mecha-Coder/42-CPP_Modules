/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:44:55 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 20:44:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    str Target;

    class outFileErrorException : public exception
    {public: virtual const char *what() const throw();};

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const str &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &original);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);

    void execute(const Bureaucrat &executor) const;
    const str getTarget() const;
};

#endif
