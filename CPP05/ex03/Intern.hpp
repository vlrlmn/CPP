# pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
  
    private:
        AForm *(Intern::*formCreators[3])(const std::string&);
        AForm* makeShrubberyForm(const std::string& target);
        AForm* makeRobotomyForm(const std::string& target);
        AForm* makePresidentialForm(const std::string& target);

    public:
        static const std::string forms[3];
        Intern();
        Intern(const Bureaucrat &original);
        const Intern &operator=(const Intern &original);
        ~Intern();

        AForm *makeForm(const std::string name, const std::string target);

        class FormCreationFailureException: public std::exception {
            private:
                const char *_msg;
            public: 
                FormCreationFailureException(): _msg("Wrong form name") {}
                FormCreationFailureException(const char *str): _msg(str) {}
                const char *what() const throw() {return _msg;}
        };
};

#endif