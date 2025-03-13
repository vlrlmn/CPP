#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Defaut", 72, 45) {
	std::cout << "Default constructor Robotomy Request Form" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy", 72, 45){
	std::cout << "Parametrized constructor Robotomy Request Form" << std::endl;
	if (target == "")
		throw (AForm::EmptyNameException());
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) {
	std::cout << "Copy constructor Robotomy Request Form" << std::endl;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
	std::cout << "Copy assignment operator Robotomy Request Form" << std::endl;
	if (this != &original) {
		AForm::operator=(original);
		this->_target = original.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor called Robotomy Request Form" <<std::endl;
}

std::string RobotomyRequestForm::getTarget() {

}

void RobotomyRequestForm::setTarget(const std::string target) {

}

void RobotomyRequestForm::_execute(void) const {

}