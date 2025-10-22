/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:44:55 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 20:44:55 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    str Target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const str &target);
    PresidentialPardonForm(const PresidentialPardonForm &original);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &original);

    void execute(const Bureaucrat &executor) const;
    const str getTarget() const;
};

#endif