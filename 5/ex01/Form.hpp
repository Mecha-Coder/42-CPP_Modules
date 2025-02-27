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
    str const	        _name;
    bool		        _signStatus;
    int const	        _signGrade;
    int const	        _executeGrade;
    static const int	maxGrade = 1;
    static const int	minGrade = 150;

    class GradeTooHighException : public std::exception
    {public:  virtual const char*what() const throw();};

    class GradeTooLowException : public std::exception
    {public: virtual const char *what() const throw();};

    class InvalidNameException : public std::exception
    {public: virtual const char *what() const throw();};

    class CannotSignException : public std::exception
    {public: virtual const char *what() const throw();};

    public:
        Form();
        Form(str name, int signGrade, int executeGrade);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        str getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getSignStatus() const;
        
        // Take Bureaucrat as the parameter
        // changes the form status to signed
        // only Bureaucrat with grade >= Form grade can sign
        // else throw error
        void beSigned(Bureaucrat &obj);
};

// Print all the form's information
std::ostream& operator<<(std::ostream& out, const Form &obj);

#endif