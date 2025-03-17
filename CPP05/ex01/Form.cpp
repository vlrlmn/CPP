#include "Form.hpp"

Form::Form(): _name("Example"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
    std::cout << "Default constructor. Default name - Example. Signed - false. Grade to sign - 150. Grade to execute - 150." << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec): _name(name), _isSigned(false), 
            _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (name.empty())
        throw EmptyNameException();
    if (gradeToExec < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
    std::cout << "Parametrized constructor called for: " << name << std::endl;
}

Form::Form(const Form &original): _name(original.getName()), 
								_gradeToSign(original.getGradeToExecute()),
								_gradeToExec(original.getGradeToExecute()) {
    *this = original;
    std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &original) {
    if (this != &original) {
		this->_isSigned = original.getSignStatus();
	}
    std::cout << "Copy assignment constructor called" << std::endl;
	return *this;
}

Form::~Form() {
     std::cout << "Destructor called Form" <<std::endl;
}

std::string Form::getName(void) const {
    return this->_name;
}

bool Form::getSignStatus(void) const {
    return this->_isSigned;
}
int Form::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const {
    return this->_gradeToExec;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGradeToSign())
        throw (Form::GradeTooLowException("Form cannot be signed! This bureaucrat doesn't have enough grade."));
    if (this->_isSigned)
        std::cout << "The form is already signed!" <<std::endl;
    else
    {
        this->_isSigned = true;
    }
}

std::ostream& operator<<(std::ostream& stream, const Form& f) {
    stream	<< "Form name: " << f.getName() 
			<< ", grade to sign: " << f.getGradeToSign()
			<< ", grade to execute: " << f.getGradeToExecute()
			<< ", sign status: " << f.getSignStatus() << std::endl;;
	return stream;
}