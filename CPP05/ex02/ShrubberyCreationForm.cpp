#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Default constructor Shrubbery Creation Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): _target(target) {
	std::cout << "Parametrized constructor Shrubbery Creation Form" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) {

}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
	std::cout << "Copy assignment operator Shrubbery Creation Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << "Destructor called Shrubbery Creation Form" <<std::endl;
}
