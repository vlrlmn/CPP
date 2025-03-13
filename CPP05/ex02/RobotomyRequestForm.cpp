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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original): AForm(original){
	std::cout << "Copy constructor Robotomy Request Form" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
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


void RobotomyRequestForm::setTarget(const std::string target) {
	if (target == "")
		throw(AForm::EmptyNameException());
	else
		this->setTarget(target);
}

void RobotomyRequestForm::_execute(void) const {
	time_t cur_time = time(NULL);
	if (cur_time % 2) {
		std::cout << "Robotomy " << this->getTarget() << " has been robotomized successfully" << std::endl;
	} 
	else {
		std::cout << "Robotomy " << this->getTarget() << " failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &ro) {
	stream  << "Form name: " << ro.getName() 
        	<< "; signature status: " << ro.getSignStatus()
			<< "; grade to sign: " << ro.getGradeToSign()
			<< "; grade to execute: " << ro.getGradeToExecute()
			<< "." << std::endl;
    return stream;
}