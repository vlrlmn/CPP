# pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
# include "AForm.hpp"
class AForm;

class Intern {
  

    public:
        Intern();
        Intern(const std::string& name, int grade);
        Intern(const Bureaucrat &original);
        const Intern &operator=(const Bureaucrat &original);
        ~Intern();

        AForm *makeForm(std::string formName, std::string formTarget);
    
        
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too low";
                }
        };

        class EmptyNameException: public std::exception {
            public:
                const char* what() const throw() {
                    return "Empty name";
                }
        };
};
    
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif