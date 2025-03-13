#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){
	std::cout << "Default constructor Presidential Pardon Form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): _target(target){
	std::cout << "Parametrized constructor Presidential Pardon Form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original): _target(target){
	std::cout << "Copy constructor Presidential Pardon Form" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &original): AForm(original) {
    std::cout << "Copy assignment constructor called Presidential Pardon Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm() {
    std::cout << "Destructor called Presidential Pardon Form" <<std::endl;
}

std::string PresidentialPardonForm::getTarget() {
	return _target;
}