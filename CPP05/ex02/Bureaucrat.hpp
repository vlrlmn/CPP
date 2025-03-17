# pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &original);
        const Bureaucrat &operator=(const Bureaucrat &original);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const &form);
        
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