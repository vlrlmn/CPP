#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        AForm *shPtr = nullptr;
        AForm *rPtr = nullptr;
        AForm *pPtr = nullptr;
        AForm *invalidPtr = nullptr;

        Bureaucrat highRank("Alice", 2);
        Bureaucrat lowRank("Bob", 149);
        try {
            shPtr = new ShrubberyCreationForm("Garden");
            rPtr = new RobotomyRequestForm("Robot");
            pPtr = new PresidentialPardonForm("Criminal");

            std::cout << std::endl << "-----------------FORMS CREATION-----------------" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! During form creation: " << e.what() << std::endl;
        }

        try {
            invalidPtr = new PresidentialPardonForm("");
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Failed to create an invalid form: " << e.what() << std::endl;
        }

        try {
            std::cout << std::endl << "-----------------SIGNING FORMS-----------------" << std::endl;
            highRank.signForm(*shPtr);
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Signing Shrubbery: " << e.what() << std::endl;
        }

        try {
            lowRank.signForm(*rPtr);
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Signing Robotomy: " << e.what() << std::endl;
        }

        try {
            std::cout << std::endl << "-----------------EXECUTING FORMS-----------------" << std::endl;
            highRank.executeForm(*shPtr);
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Executing Shrubbery: " << e.what() << std::endl;
        }

        try {
            lowRank.executeForm(*rPtr);
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Executing unsigned Robotomy: " << e.what() << std::endl;
        }

        try {
            highRank.signForm(*pPtr);
            highRank.executeForm(*pPtr);
        } catch (const std::exception& e) {
            std::cout << "EXCEPTION! Signing/executing Presidential: " << e.what() << std::endl;
        }

        std::cout << std::endl << "-----------------CLEANUP-----------------" << std::endl;
        delete shPtr;
        delete rPtr;
        delete pPtr;
        delete invalidPtr;
    } catch (std::exception &e) {
        std::cout << "EXCEPTION! " << e.what() << std::endl;
    }
    return 0;
}
