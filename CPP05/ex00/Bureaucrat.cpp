#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default name"), grade(1) {
    std::cout << "Default constructor" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &original): name(original.name), grade(original.grade) {
    std::cout << "Copy constructor" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &original) {
    if (this != &original)
    {
        this->grade = original.grade;
    }
    std::cout << "Copy assignment constructor called" << std::endl;
    return *this;
};

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" <<std::endl;
};

const std::string Bureaucrat::getName() const{
    return (this->name);
};

int Bureaucrat::getGrade() const{
    return (this->grade);
};

int Bureaucrat::incrementGrade() {
    try
    {

    }
    catch (std::exception & e)
    {

    }
};

int Bureaucrat::decrementGrade() {
    try
    {

    }
    catch (std::exception & e)
    {
        
    }
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b)
{
    stream << b.getName() << " ,bureaucrat grade " << b.getGrade() << ".";
    return stream;
}