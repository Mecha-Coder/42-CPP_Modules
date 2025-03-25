/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:09:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 18:27:17 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    const str Name;
    const int SignGrade;
    const int ExecuteGrade;
    bool IsSign;

protected:
    class GradeTooHighException : public exception
    {
        str Msg;
        public:
        GradeTooHighException(const str &msg); 
        virtual ~GradeTooHighException() throw() {}
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public exception
    {
        str Msg;  
        public:
        GradeTooLowException(const str &msg);
        virtual ~GradeTooLowException() throw() {}
        virtual const char *what() const throw();
    };

    class NotApproveException : public exception
    {public: virtual const char *what() const throw();};

public:
    AForm();
    AForm(const str &name, int signGrade, int executeGrade);
    AForm(const AForm &original);
    virtual ~AForm();
    AForm& operator=(const AForm &original);

    const str &getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getIsSign() const;

    void beSigned(Bureaucrat &obj);
    virtual void execute(const Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif