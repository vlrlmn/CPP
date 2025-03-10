# pragma once

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &original);
        Bureaucrat &operator=(const Bureaucrat &original);
        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;
        int incrementGrade();
        int decrementGrade();

};
    
    std::ostream& operator<<(std::ostream& stream, const Bureaucrat& b);

#endif