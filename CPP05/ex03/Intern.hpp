# pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum {
    SHRUBBERY,
    ROBOTOMY,
    PRESIDENTIAL,
    NUM_FORMS
};

class Intern {
  
    private:
        AForm* (Intern::*formCreators[NUM_FORMS])(const std::string&) const;
        AForm* makeShrubberyForm(const std::string& target);
        AForm* makeRobotomyForm();
        AForm* makePresidentialForm();

    public:
        Intern();
        Intern(const std::string& name, int grade);
        Intern(const Bureaucrat &original);
        const Intern &operator=(const Intern &original);
        ~Intern();

        AForm *makeForm(const std::string formName, const std::string formTarget);
    
        
};
    
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif