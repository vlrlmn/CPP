#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential", 25, 5) {
	std::cout << "Default constructor Presidential Pardon Form" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential", 25, 5) {
	std::cout << "Parametrized constructor Presidential Pardon Form" << std::endl;
	if (target == "")
		throw (AForm::EmptyNameException());
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original): AForm(original) {
	std::cout << "Copy constructor Presidential Pardon Form" << std::endl;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &original) {
    std::cout << "Copy assignment constructor called Presidential Pardon Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor called Presidential Pardon Form" <<std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::setTarget(std::string target) {
	if (target == "")
		throw (AForm::EmptyNameException());
	else
		this->_target = target;
}

void PresidentialPardonForm::_execute() const {
	std::cout << "The target " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
