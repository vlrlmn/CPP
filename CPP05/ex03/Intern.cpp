#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const std::string& name, int grade) {}
Intern::Intern(const Bureaucrat &original) {}
const Intern& Intern::operator=(const Bureaucrat &original){}
Intern::~Intern() {}

void Intern::makeForm(std::string formName, std::string formTarget) {}