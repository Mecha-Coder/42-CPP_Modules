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

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    const str name;
    bool      isSigned;
    const int signGrade;
    const int executeGrade;

    class GradeTooHighException : public std::exception
    {public:  virtual const char*what() const throw();};

    class GradeTooLowException : public std::exception
    {public: virtual const char *what() const throw();};

    class InvalidNameException : public std::exception
    {public: virtual const char *what() const throw();};


    public:
        Form();
        Form(str setName, int setApprover, int setActioner);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        str getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;
        
        void beSigned(Bureaucrat &obj);
};

std::ostream& operator<<(std::ostream& out, const Form &obj);

#endif