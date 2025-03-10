#include "Bureaucrat.hpp"

    Bureaucrat::Bureaucrat(){};

    Bureaucrat::Bureaucrat(const Bureaucrat &original) {
        *this = original;
        std::cout << "Copy constructor" << std::endl;
    };

    Bureaucrat& Bureaucrat::&operator=(const Bureaucrat &original) {
        if (this != &original)
        {
            // this->name = original.name;
            this->grade = original.grade;
        }
        std::cout << "Copy assignment constructor called" << std::endl;
        return *this;
    };

    Bureaucrat::~Bureaucrat() {
        std::cout << "Destructor called" <<std::endl;
    };

    const std::string getName();
    int getGrade();

    int incrementGrade();
    int decrementGrade();