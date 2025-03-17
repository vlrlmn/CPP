# pragma once

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExec;
    public:

        Form();
        Form(const std::string& name, const int gradeToSign, const int gradeToExec);
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
                GradeTooHighException():_msg("Form cannot be created. Grade is too high!") {}
                GradeTooHighException(const char *str):_msg(str) {}
                const char* what() const throw() { return _msg;}
            private:
                const char *_msg;
        };

        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException():_msg("Form cannot be created. Grade is too low!") {}
                GradeTooLowException(const char *str):_msg(str) {}
                const char* what() const throw() { return _msg; }
            private:
                const char *_msg;
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