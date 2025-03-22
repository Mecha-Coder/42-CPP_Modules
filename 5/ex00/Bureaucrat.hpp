/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:51:28 by jpaul             #+#    #+#             */
/*   Updated: 2025/02/25 18:09:22 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#define RED "\033[31m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"

#define maxGrade 1
#define minGrade 150

typedef std::string str;

class Bureaucrat {
    str const name;
    int       grade;

    class GradeTooHighException : public std::exception
    {public:  virtual const char*what() const throw();};

    class GradeTooLowException : public std::exception
    {public: virtual const char *what() const throw();};

    class InvalidNameException : public std::exception
    {public: virtual const char *what() const throw();};

    public:
        Bureaucrat();
        Bureaucrat(str name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat&	operator=(const Bureaucrat &other);
        ~Bureaucrat();

        str getName() const;
        int getGrade() const;
        void upGrade();
        void downGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif
