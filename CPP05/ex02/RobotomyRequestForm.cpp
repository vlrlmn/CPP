#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Default constructor Robotomy Request Form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): _target(target) {
	std::cout << "Parametrized constructor Robotomy Request Form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) {

}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
	std::cout << "Copy assignment operator Robotomy Request Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Destructor called Robotomy Request Form" <<std::endl;
}
