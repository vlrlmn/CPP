#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
    formCreators[SHRUBBERY] = &Intern::makeShrubberyForm;
    formCreators[ROBOTOMY] = &Intern::makeRobotomyForm;
    formCreators[PRESIDENTIAL] = &Intern::makePresidentialForm;
}

Intern::Intern(const std::string& name, int grade) {}

Intern::Intern(const Bureaucrat &original) {
    *this = original;
}

const Intern& Intern::operator=(const Intern &original) {
    if (this != &original)
    {

    }
    return *this;
}

Intern::~Intern() {
    std::cout << "Destructor for Intern called" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    std::cout << "Intern creates " << formName << std::endl;
}

AForm* (Intern::*formCreators[NUM_FORMS])(const std::string&) const;

AForm* Intern::makeShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* makePresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}