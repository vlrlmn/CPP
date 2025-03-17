#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    Intern someRandomIntern;
    Bureaucrat higGgrade("Bob", 2);
	Bureaucrat lowGrade("Alice", 150);
    AForm *shPtr = nullptr;
    AForm *rPtr = nullptr;
    AForm *pPtr = nullptr;

    try {
		// Create form within intern
		std::cout << std::endl << "---------------CREATE FORM---------------" << std::endl;
        shPtr = someRandomIntern.makeForm("shrubbery creation", "garden");
        rPtr = someRandomIntern.makeForm("robotomy request", "machina");
        pPtr = someRandomIntern.makeForm("presidential pardon", "crime");
    } catch (std::exception &e) {
        std::cout << "EXCEPTION: Failed to create forms: " << e.what() << std::endl;
    }

    try {
        std::cout << std::endl << "---------------SHRUBBERY FORM---------------" << std::endl;
        higGgrade.signForm(*shPtr);
        higGgrade.executeForm(*shPtr);
    } catch (std::exception &e) {
        std::cout << "EXCEPTION: Error with Shrubbery Form: " << e.what() << std::endl;
    }

    try {
		//Invalid: no signature
		std::cout << std::endl << "---------------ROBOTOMY FORM---------------" << std::endl;
        higGgrade.executeForm(*rPtr);
    } catch (std::exception &e) {
        std::cout << "EXCEPTION: Error with Robotomy Form: " << e.what() << std::endl;
    }

	try {
		// Invalid
        lowGrade.signForm(*pPtr);
        lowGrade.executeForm(*pPtr);
    } catch (std::exception &e) {
        std::cout << "EXCEPTION: Error with Presidential Form: " << e.what() << std::endl;
    }

    try {
		// Valid
        std::cout << std::endl << "---------------PRESIDENTIAL FORM---------------" << std::endl;
        higGgrade.signForm(*pPtr);
		higGgrade.executeForm(*pPtr);
    } catch (std::exception &e) {
        std::cout << "EXCEPTION: Error with Presidential Form: " << e.what() << std::endl;
    }

    std::cout << std::endl << "---------------CLEANUP---------------" << std::endl;
    delete shPtr;
    delete rPtr;
    delete pPtr;

    return 0;
}
