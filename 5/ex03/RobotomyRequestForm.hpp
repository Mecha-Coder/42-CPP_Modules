/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:50:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 21:50:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm 
{
    str Target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const str &target);
    RobotomyRequestForm(const RobotomyRequestForm &original);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &original);

    const str getTarget() const;
    void execute(const Bureaucrat &executor) const;
};

#endif