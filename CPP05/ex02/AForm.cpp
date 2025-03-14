#include "AForm.hpp"

AForm::AForm(): _name("Example"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
    std::cout << "Default constructor. Default name - Example. Signed - false. Grade to sign - 150. Grade to execute - 150." << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec): _name(name), _isSigned(false), 
            _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (name.empty())
        throw EmptyNameException();
    if (gradeToExec < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Parametrized constructor called for: " << name << std::endl;
}

AForm::AForm(const AForm &original): _name(original.getName()), 
								_gradeToSign(original.getGradeToExecute()),
								_gradeToExec(original.getGradeToExecute()) {
    *this = original;
    std::cout << "Copy constructor called" << std::endl;
}

const AForm& AForm::operator=(const AForm &original) {
    if (this != &original) {
		this->_isSigned = original.getSignStatus();
	}
    std::cout << "Copy assignment constructor called" << std::endl;
	return *this;
}

AForm::~AForm() {
     std::cout << "Destructor called" <<std::endl;
}

std::string AForm::getName(void) const {
    return this->_name;
}

bool AForm::getSignStatus(void) const {
    return this->_isSigned;
}
int AForm::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const {
    return this->_gradeToExec;
}

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGradeToSign())
        throw (AForm::GradeTooLowException("Form cannot be signed! This bureaucrat doesn't have enough grade."));
    if (this->_isSigned)
        std::cout << "The form is already signed!" <<std::endl;
    else
    {
        this->setSignStatus(true);
        std::cout	<< "Bueraucrat " << b.getName()
				<< " signed " << this->getName()
				<< std::endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const AForm& f) {
    stream	<< "Form name: " << f.getName() 
			<< ", grade to sign: " << f.getGradeToSign()
			<< ", grade to execute: " << f.getGradeToExecute()
			<< ", sign status: " << f.getSignStatus() << std::endl;
	return stream;
}

int AForm::execute(Bureaucrat const & executor) const {
    try {
        if (this->getSignStatus() == false) {
            std::cout << "Form " << this->getName() << " cannot be executed! The form is not signed!" << std::endl;
        } else if (executor.getGrade() > this->getGradeToExecute()) {
            throw (AForm::GradeTooLowException());
        }
        this->_execute();
    } catch (AForm::GradeTooLowException) {
        std::cout << "Form " << this->getName() << "cannot be executed because " << executor.getName() << "doesn't have enough grade" << std::endl;
        throw;
    }
    return 1;
}

void AForm::setSignStatus(const bool status) {
    this->_isSigned = status;
}