/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:50:49 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/27 14:50:49 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    const str name;
    bool      isSigned;
    const int signGrade;
    const int executeGrade;

    class GradeTooHighException : public std::exception
    {
        str msg;
        public: 
            GradeTooHighException(str s);
            virtual ~GradeTooHighException() throw() {} 
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        str msg;
        public:
            GradeTooLowException(str s);
            virtual ~GradeTooLowException() throw() {} 
            virtual const char *what() const throw();
    };

    class InvalidNameException : public std::exception
    {public: virtual const char *what() const throw();};


    public:
        AForm();
        AForm(str setName, int setApprover, int setActioner);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        str getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;
        
        void beSigned(Bureaucrat &approver);
        virtual void execute(Bureaucrat &executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm &obj);

#endif