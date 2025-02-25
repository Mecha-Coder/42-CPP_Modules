/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:28:20 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 19:49:58 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    public:
        Form();
        Form(str name, int signGrade);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        str getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getSignStatus() const;

        // - changes the form status to signed
        // - if Bureaucrat grade >= Form grade
        // - else throw error
        void beSigned(Bureaucrat &obj) const;

        // if form got signed
        // <bureaucrat> signed <form>
        // else <bureaucrat> couldn’t sign <form> because <reason>.
        void signForm();
};

std::ostream& operator<<(std::ostream& os, const Form &obj);




