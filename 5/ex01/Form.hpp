/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:09:32 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 16:49:48 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    const string Name;
    const int SignGrade;
    const int ExecuteGrade;
    bool IsSign;

    class GradeTooHighException : public exception
    {
        string Msg;
        public:
        GradeTooHighException(const string &msg); 
        virtual ~GradeTooHighException() throw() {}
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public exception
    {
        string Msg;  
        public:
        GradeTooLowException(const string &msg);
        virtual ~GradeTooLowException() throw() {}
        virtual const char *what() const throw();
    };

public:
    Form();
    Form(const string &name, int signGrade, int executeGrade);
    Form(const Form &original);
    ~Form();
    Form& operator=(const Form &original);

    const string &getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    bool getIsSign() const;

    void beSigned(Bureaucrat &obj);

};

ostream &operator<<(ostream &out, const Form &obj);

#endif