#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

// int main(void)
// {
// 	Intern someRandomIntern;
// 	AForm* rrf;
// 	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// }
int main(void)
{
	try {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		Bureaucrat a("Bob", 2);
		a.executeForm(*rrf);

		Intern intern;
		AForm *shPtr = intern.makeForm("shrubbery creation", "yard");
		AForm *rPtr = intern.makeForm("robotomy request", "robo");
		AForm *pPtr = intern.makeForm("presidential pardon", "mall");
		// AForm *wPtr = intern.makeForm("presidential pardon", "");
		// (void)wPtr;
		std::cout << std::endl << "SHRUBBERY FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	// Printing and Executing ShrubberyCreationForm through AForm pointer 
		if (ShrubberyCreationForm *newPtr = dynamic_cast<ShrubberyCreationForm *>(shPtr)) {
			std::cout << *shPtr << std::endl;
		} else {
			std::cout << "Failed to cast AForm* to ShrubberyCreationForm*" << std::endl;
		}
		a.signForm(*shPtr);
		a.executeForm(*shPtr);
		
		std::cout << std::endl << "ROBOTOMY FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		// a.signForm(*rPtr);
		a.executeForm(*rPtr);	

		std::cout << std::endl << "PRESIDENTIAL FORM >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
		a.signForm(*pPtr);
		a.executeForm(*pPtr);

		std::cout << std::endl << "DONE ----------------------------------------------------" << std::endl;

		// AForm *sPtr = intern.makeForm("wrong form name", "target");
		// (void)sPtr;
		delete shPtr;
		delete rPtr;
		delete pPtr;
	} catch (std::exception &e) {
		std::cout << std::endl << "<EXCEPTION>: Caught in main(): " << e.what() << std::endl;
	}

	return 0;
}