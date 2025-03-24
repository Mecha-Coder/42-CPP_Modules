/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:42:19 by jpaul             #+#    #+#             */
/*   Updated: 2025/03/22 16:50:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
typedef std::string str;
typedef std::exception exception;

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

class AForm;

class Bureaucrat {
    const str Name;
    int Grade;

    class GradeTooHighException : public exception
    {public: virtual const char *what() const throw();};

    class GradeTooLowException : public exception
    {public: virtual const char *what() const throw();};
    
public:
    Bureaucrat();
    Bureaucrat(const str &name, int grade);
    Bureaucrat(const Bureaucrat &original);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &original);

    const str &getName() const;
    int getGrade() const;

    void increment();        
    void decrement();
    void signForm(bool status, const str &formName, str reason="");
    bool executeForm(const AForm &form) const;
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
