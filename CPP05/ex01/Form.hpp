# pragma once

#ifndef FORM_HPP
#define FORM_HPP


#include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    public:

        Form();
        Form(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExec);
        Form(const Form &original);
        Form &operator=(const Form &original);
        ~Form();

        std::string getName(void) const;
		bool getSignStatus(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat &b);

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

         class EmptyNameException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Name string is empty";
                }
        };

};
std::ostream& operator<<(std::ostream& stream, const Form& f);

#endif