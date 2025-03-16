#include "Intern.hpp"

const std::string Intern::forms[3] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
    formCreators[0] = &Intern::makeShrubberyForm;
    formCreators[1] = &Intern::makeRobotomyForm;
    formCreators[2] = &Intern::makePresidentialForm;

}

Intern::Intern(const Bureaucrat &original) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = original;
}

const Intern& Intern::operator=(const Intern &original) {
    std::cout << "Intern copy assignment constructor called" << std::endl;
    (void)original;
    return *this;
}

Intern::~Intern() {
    std::cout << "Destructor called for Intern" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    std::cout << "Intern creates " << formName << std::endl;
}

AForm* Intern::makeShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string name, const std::string target) {
    AForm *formPtr = NULL;
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i]) {
            formPtr = (this->*formCreators[i])(target);
        }
    }
    if (!formPtr)
        throw(FormCreationFailureException());
    return formPtr;
}