#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Example"), _grade(150) {
    std::cout << "Default constructor. Default name - Example. Grade - 150" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &original): _name(original._name), _grade(original._grade) {
    std::cout << "Copy constructor for bureaucrat" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {

    if (name.empty())
        throw EmptyNameException();
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->_grade = grade;
    std::cout << "Parametrized constructor called for bureaucrat"<< std::endl;

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original) {
    if (this != &original) {
        this->_grade = original.getGrade();
    }
    std::cout << "Copy assignment constructor for bureaucrat" << std::endl;
    return *this;
};

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called for bureaucrat" <<std::endl;
};

const std::string Bureaucrat::getName() const {
    return this->_name;
};

int Bureaucrat::getGrade() const {
    return this->_grade;
};

void Bureaucrat::incrementGrade(void) {
    if (_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
};

void Bureaucrat::decrementGrade(void) {
    if (_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
};

void Bureaucrat::signForm(Form &form) {
    try {
        if (!form.getSignStatus()) {
            form.beSigned(*this);
            std::cout   << "Bureaucrat " << this->getName() << " signed " 
                        << form.getName() << std::endl;
        }
        else
        {
            std::cout << "This form is already signed!" << std::endl;
        }
    } catch (Form::GradeTooLowException) {
        std::cout   << "Bureaucrat " << this->getName() << " couldn't sign " << form.getName()
                    << " because grade should be up to " << form.getGradeToSign() << std::endl;
        throw;           
    }
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
    stream  << "Bureaucrat's name: " << b.getName() 
            << "; bureaucrat's grade: " << b.getGrade() << ".";
    return stream;
}